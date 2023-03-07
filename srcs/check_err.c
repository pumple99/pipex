/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:15:17 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/07 17:15:23 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //pipe dup2
#include <stdio.h> //perror
#include <stdlib.h> //exit
#include "../libft/pf_printf.h"

void	check_pipe(int *fds)
{
	if (pipe(fds) == 0)
		return ;
	perror("bash: pipe failed");
	exit(EXIT_FAILURE);
}

int	check_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("bash: fork failed");
		exit(EXIT_FAILURE);
	}
	else
		return (pid);
}

void	check_close(int fd)
{
	if (close(fd) == 0)
		return ;
	perror("bash: close failed");
	exit(EXIT_FAILURE);
}

int	check_dup2(int fd1, int fd2)
{
	int	re;

	re = dup2(fd1, fd2);
	if (re != -1)
		return (re);
	perror("bash: dup2 failed");
	exit(EXIT_FAILURE);
}

void	check_open_fd(char *path, int fd)
{
	if (fd != -1)
		return ;
	fd_printf(2, "bash: %s", path);
	perror("");
	exit(EXIT_FAILURE);
}
