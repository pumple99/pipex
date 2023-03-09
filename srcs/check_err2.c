/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:53 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/09 17:53:12 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //access
#include <stdlib.h> //exit free
#include <stdio.h> //perror
#include "../libft/pf_printf.h"
#include "../pipex_consts.h"

char	**check_malloc2(char **addr)
{
	if (addr)
		return (addr);
	perror("bash: malloc failed");
	exit(EXIT_FAILURE);
}

char	*check_malloc(char *addr)
{
	if (addr)
		return (addr);
	perror("bash: malloc failed");
	exit(EXIT_FAILURE);
}

char	*check_gnl(char *gnl_line)
{
	if (gnl_line == (char *)1)
	{
		perror("bash: gnl failed");
		exit(EXIT_FAILURE);
	}
	return (gnl_line);
}

int	check_access(char *path)
{
	if (access(path, F_OK) != 0)
		return (1);
	if (access(path, X_OK) == 0)
		return (0);
	fd_printf(2, "bash: %s: ", path);
	perror("");
	exit(PERMISSION_DENIED);
	return (1);
}
