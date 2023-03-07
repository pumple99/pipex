/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:56:12 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/13 21:07:54 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "gnl.h"

void	delete_node(int fd, t_bnode **bnode)
{
	t_bnode	*pre;
	t_bnode	*temp;

	pre = *bnode;
	if (pre == 0)
		return ;
	if (pre->fd == fd)
	{
		temp = pre;
		*bnode = pre->next;
		free(temp);
		return ;
	}
	while (pre->next)
	{
		if (pre->next->fd == fd)
		{
			temp = pre->next;
			pre->next = pre->next->next;
			free(temp);
			return ;
		}
		pre = pre->next;
	}
}

size_t	s_len(char const *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	len_until_nl(const char *s, size_t range)
{
	size_t	idx;

	idx = 0;
	while (idx < range && s[idx])
	{
		if (s[idx] == '\n')
			return (1 + idx);
		idx++;
	}
	return (0);
}

char	*s_join_free_s1(char *s1, char *s2, size_t byte, int *err)
{
	size_t	len1;
	size_t	idx;
	char	*sj;

	len1 = s_len(s1);
	if (s2 == 0)
		byte = 0;
	sj = (char *)malloc(len1 + byte + 1);
	if (sj == 0)
	{
		*err = 1;
		free(s1);
		return (0);
	}
	idx = 0 - 1;
	while (++idx < len1)
		sj[idx] = s1[idx];
	idx = 0 - 1;
	while (++idx < byte)
		sj[len1 + idx] = s2[idx];
	sj[len1 + byte] = 0;
	free(s1);
	return (sj);
}

char	*sub_s(char const *s, unsigned int start, size_t len, int *err)
{
	char	*ss;
	size_t	idx;

	if (s == 0)
		return (0);
	ss = (char *)malloc(len + 1);
	if (ss == 0)
	{
		*err = 1;
		return (0);
	}
	idx = 0 - 1;
	while (++idx < len)
		ss[idx] = s[start + idx];
	ss[len] = 0;
	return (ss);
}
