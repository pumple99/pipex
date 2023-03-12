/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:53 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/12 17:59:06 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //access
#include <stdlib.h> //EXIT_FAILURE
#include "../libft/pf_printf.h" //fd_printf
#include "../pipex.h" //perr_exit
#include "../pipex_consts.h" //PERMISSION_DENIED

char	**check_malloc2(char **addr)
{
	if (addr)
		return (addr);
	perr_exit("pipex: malloc failed", EXIT_FAILURE);
	return (0);
}

char	*check_malloc(char *addr)
{
	if (addr)
		return (addr);
	perr_exit("pipex: malloc failed", EXIT_FAILURE);
	return (0);
}

char	*check_gnl(char *gnl_line)
{
	if (gnl_line == (char *)1)
	{
		perr_exit("pipex: gnl failed", EXIT_FAILURE);
		return (0);
	}
	return (gnl_line);
}

int	check_access(char *path)
{
	if (access(path, F_OK) != 0)
		return (1);
	if (access(path, X_OK) == 0)
		return (0);
	fd_printf(2, "pipex: %s: ", path);
	perr_exit("", PERMISSION_DENIED);
	return (1);
}
