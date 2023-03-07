/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:55:16 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/13 21:08:48 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"

t_bnode	*find_or_new(int fd, t_bnode **bnode, int *err)
{
	t_bnode	*temp;
	t_bnode	*cur;

	cur = *bnode;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	temp = (t_bnode *)malloc(sizeof(t_bnode));
	if (temp == 0)
	{
		*err = 1;
		return (0);
	}
	temp->fd = fd;
	temp->backup = 0;
	temp->next = *bnode;
	*bnode = temp;
	return (temp);
}

static char	*getline(char **backup, int *err)
{
	size_t	nl_len;
	char	*line;
	char	*temp_backup;

	nl_len = len_until_nl(*backup, s_len(*backup));
	if (nl_len == 0 || nl_len == s_len(*backup))
	{
		line = *backup;
		*backup = 0;
		return (line);
	}
	line = sub_s(*backup, 0, nl_len, err);
	temp_backup = *backup;
	*backup = sub_s(*backup, nl_len, s_len(*backup) - nl_len, err);
	free(temp_backup);
	return (line);
}

static void	read_until_nl(int fd, char **backup, int *err)
{
	char	buf[BUFFER_SIZE];
	ssize_t	read_byte;

	if (len_until_nl(*backup, s_len(*backup)))
		return ;
	read_byte = BUFFER_SIZE;
	while (read_byte == BUFFER_SIZE)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		*backup = s_join_free_s1(*backup, buf, read_byte, err);
		if (*err || len_until_nl(buf, BUFFER_SIZE))
			return ;
	}
}

static char	*re_check(int fd, int *err, t_bnode **bnode, char *re_str)
{
	char	**backup;

	backup = &(find_or_new(fd, bnode, err)->backup);
	if (*err)
	{
		free(re_str);
		free(*backup);
		*backup = 0;
		delete_node(fd, bnode);
		return ((char *)1);
	}
	if (re_str && re_str[0] == 0)
	{
		free(re_str);
		re_str = 0;
		delete_node(fd, bnode);
	}
	return (re_str);
}

char	*get_next_line(int fd)
{
	static t_bnode	*bnode;
	int				err;
	t_bnode			*n;
	char			**backup;

	err = 0;
	n = find_or_new(fd, &bnode, &err);
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		err = 1;
	if (err)
		return (re_check(fd, &err, &bnode, 0));
	backup = &(n->backup);
	read_until_nl(fd, backup, &err);
	return (re_check(fd, &err, &bnode, getline(backup, &err)));
}
