/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:09:57 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/09 18:18:31 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include <unistd.h> //execve
#include "../libft/libft.h" //ft_strncmp, ft_split
#include "../pipex.h" //parse_cmd

static char	*char_join(char *s1, char *s2, char c)
{
	size_t	len1;
	size_t	len2;
	size_t	idx;
	char	*sj;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	sj = (char *)malloc(len1 + len2 + 2);
	if (sj == 0)
		return (0);
	idx = -1;
	while (++idx < len1)
		sj[idx] = s1[idx];
	sj[idx] = c;
	idx = -1;
	while (++idx < len2)
		sj[len1 + 1 + idx] = s2[idx];
	sj[len1 + 1 + len2] = 0;
	return (sj);
}

static char	**empty_path(void)
{
	char	**path;

	path = (char **)malloc(sizeof(char *) * 2);
	path[0] = (char *)malloc(sizeof(char));
	path[1] = 0;
	path[0][0] = 0;
	return (path);
}

char	**get_path(char **envp)
{
	int		idx;
	int		is_path_exist;

	idx = 0;
	is_path_exist = 0;
	while (envp[idx])
	{
		if (ft_strncmp(envp[idx], "PATH=", 5) == 0)
		{
			is_path_exist = 1;
			break ;
		}
		++idx;
	}
	if (is_path_exist)
		return (ft_split(envp[idx] + 5, ':'));
	return (empty_path());
}

void	exe_if_possible(char **parsed_cmd, char **path, char *envp[])
{
	int		idx;
	char	*temp;

	idx = -1;
	while (path[++idx])
	{
		temp = check_malloc(char_join(path[idx], parsed_cmd[0], '/'));
		if (check_access(temp) == 0)
			execve(temp, parsed_cmd, envp);
		free(temp);
	}
}
