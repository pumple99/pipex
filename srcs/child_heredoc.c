/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:17:11 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/08 19:35:03 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //execve
#include <fcntl.h> //open
#include <stdio.h> //perror
#include <stdlib.h> //exit
#include "../pipex.h"
#include "../libft/pf_printf.h" //fd_printf
#define STDIN 0
#define STDOUT 1

static void	first_child_heredoc(char *argv[], char *envp[], t_all *all)
{
	int	fd;

	check_close((all->right_fds)[0]);
	check_dup2(all->right_fds[1], STDOUT);
	fd = open(HEREDOC_TEMP, O_RDONLY);
	check_open_fd(HEREDOC_TEMP, fd);
	check_dup2(fd, STDIN);
	work(argv, envp, all);
}

static void	mid_child_heredoc(char *argv[], char *envp[], t_all *all)
{
	check_close((all->left_fds)[1]);
	check_close((all->right_fds)[0]);
	check_dup2(all->left_fds[0], STDIN);
	check_dup2(all->right_fds[1], STDOUT);
	work(argv, envp, all);
}

static void	last_child_heredoc(char *argv[], char *envp[], t_all *all)
{
	int	fd;

	check_close((all->left_fds)[1]);
	check_dup2(all->left_fds[0], STDIN);
	fd = open(argv[all->child_idx + 1], O_WRONLY | O_CREAT | O_APPEND, 0755);
	check_open_fd(argv[all->child_idx + 1], fd);
	check_dup2(fd, STDOUT);
	work(argv, envp, all);
}

void	child_work_heredoc(char *argv[], char *envp[], t_all *all)
{
	if (all->child_idx == 3)
		first_child_heredoc(argv, envp, all);
	else if (all->child_idx == all->child_num + 2)
		last_child_heredoc(argv, envp, all);
	else
		mid_child_heredoc(argv, envp, all);
}
