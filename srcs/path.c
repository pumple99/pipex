/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:09:57 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/27 16:29:52 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //access
#include <stdlib.h> //free
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

char	**get_path(char **envp)
{
	int	idx;

	idx = 0;
	while (envp[idx])
	{
		if (ft_strncmp(envp[idx], "PATH=", 5) == 0)
			break ;
		++idx;
	}
	return (ft_split(envp[idx] + 5, ':'));
}

void	exe_if_possible(char **parsed_cmd, char **path, char *envp[])
{
	int		idx;
	char	*temp;

	idx = -1;
	while (path[++idx])
	{
		temp = check_malloc(char_join(path[idx], parsed_cmd[0], '/'));
		if (access(temp, X_OK) == 0)
			execve(temp, parsed_cmd, envp);
		free(temp);
	}
}
