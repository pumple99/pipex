/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:17 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/12 17:50:11 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //pipe dup2
#include <stdlib.h> //EXIT_FAILURE
#include "../libft/pf_printf.h"  //fd_printf
#include "../pipex.h" //perr_exit

void	check_pipe(int *fds)
{
	if (pipe(fds) == 0)
		return ;
	perr_exit("pipex: pipe failed", EXIT_FAILURE);
}

int	check_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perr_exit("pipex: fork failed", EXIT_FAILURE));
	else
		return (pid);
}

void	check_close(int fd)
{
	if (close(fd) == 0)
		return ;
	perr_exit("pipex: close failed", EXIT_FAILURE);
}

int	check_dup2(int fd1, int fd2)
{
	int	re;

	re = dup2(fd1, fd2);
	if (re != -1)
		return (re);
	return (perr_exit("pipex: dup2 failed", EXIT_FAILURE));
}

void	check_open_fd(char *path, int fd)
{
	if (fd != -1)
		return ;
	fd_printf(2, "pipex: %s: ", path);
	perr_exit("", EXIT_FAILURE);
}
