/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:18:45 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/10 19:04:19 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //execve
#include <fcntl.h> //open
#include <stdio.h> //perror
#include <stdlib.h> //exit
#include "../pipex.h"
#include "../libft/pf_printf.h" //fd_printf
#include "../libft/libft.h" //ft_strchr
#include "../pipex_consts.h"

void	work(char *argv[], char *envp[], t_all *all)
{
	char	**path;
	char	**parsed_cmd;

	path = all->path;
	parsed_cmd = check_malloc2(parse_cmd(argv[all->child_idx]));
	exe_if_possible(parsed_cmd, path, envp);
	check_access(parsed_cmd[0]);
	if (ft_strchr(parsed_cmd[0], '/'))
		execve(parsed_cmd[0], parsed_cmd, envp);
	fd_printf(2, "pipex: %s: %s\n", parsed_cmd[0], CMD_NOT_FOUND_STR);
	exit(CMD_NOT_FOUND);
}

static void	first_child(char *argv[], char *envp[], t_all *all)
{
	int	fd;

	check_close((all->right_fds)[0]);
	check_dup2(all->right_fds[1], STDOUT);
	fd = open(argv[1], O_RDONLY);
	check_open_fd(argv[1], fd);
	check_dup2(fd, STDIN);
	work(argv, envp, all);
}

static void	mid_child(char *argv[], char *envp[], t_all *all)
{
	check_close((all->left_fds)[1]);
	check_close((all->right_fds)[0]);
	check_dup2(all->left_fds[0], STDIN);
	check_dup2(all->right_fds[1], STDOUT);
	work(argv, envp, all);
}

static void	last_child(char *argv[], char *envp[], t_all *all)
{
	int	fd;

	check_close((all->left_fds)[1]);
	check_dup2(all->left_fds[0], STDIN);
	fd = open(argv[all->child_idx + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	check_open_fd(argv[all->child_idx + 1], fd);
	check_dup2(fd, STDOUT);
	work(argv, envp, all);
}

void	child_work(char *argv[], char *envp[], t_all *all)
{
	if (all->child_idx == 2)
		first_child(argv, envp, all);
	else if (all->child_idx == all->child_num + 1)
		last_child(argv, envp, all);
	else
		mid_child(argv, envp, all);
}
