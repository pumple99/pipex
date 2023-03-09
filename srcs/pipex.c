/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:17:32 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/09 15:57:48 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> //open
#include <unistd.h> //pid_t write
#include <stdlib.h> //free
#include "../pipex.h" //...
#include "../libft/libft.h" //ft_strncmp ft_strput_fd ft_strlen
#include "../libft/gnl.h" //gnl

static void	close_left_and_move(int *l, int *r, int idx)
{
	if (idx != 2)
	{
		check_close(l[0]);
		check_close(l[1]);
	}
	l[0] = r[0];
	l[1] = r[1];
}

static int	is_same_with_limiter(char *limiter, char *line)
{
	size_t	len;

	if (line == 0)
		return (0);
	len = ft_strlen(limiter);
	if (ft_strncmp(limiter, line, len) != 0)
		return (0);
	else if (line[len] == '\n')
		return (1);
	return (0);
}

static void	read_heredoc(char *argv[])
{
	int		fd;
	char	*line;

	fd = open(HEREDOC_TEMP, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	check_open_fd(HEREDOC_TEMP, fd);
	while (1)
	{
		line = get_next_line(0);
		if (is_same_with_limiter(argv[2], line))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	check_close(fd);
}

static int	heredoc_main(int argc, char *argv[], char *envp[])
{
	t_all	all;
	pid_t	pid;

	if (argc < 6)
		return (err_exit("here_doc needs more than 4 arguments\n"));
	read_heredoc(argv);
	all.child_idx = 2;
	all.child_num = argc - 4;
	pid = 1;
	while (all.child_idx < argc - 2 && pid != 0)
	{
		++all.child_idx;
		if (all.child_idx != argc - 2)
			check_pipe(all.right_fds);
		pid = check_fork();
		if (pid != 0)
			close_left_and_move(all.left_fds, all.right_fds, all.child_idx - 1);
	}
	if (pid == 0)
		child_work_heredoc(argv, envp, &all);
	else
		wait_childs_heredoc(all.child_num, pid);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_all	all;
	pid_t	pid;

	if (argc < 5)
		return (err_exit("pipex needs more than 3 arguments\n"));
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		return (heredoc_main(argc, argv, envp));
	all.child_idx = 1;
	all.child_num = argc - 3;
	pid = 1;
	while (all.child_idx < argc - 2 && pid != 0)
	{
		++all.child_idx;
		if (all.child_idx != argc - 2)
			check_pipe(all.right_fds);
		pid = check_fork();
		if (pid != 0)
			close_left_and_move(all.left_fds, all.right_fds, all.child_idx);
	}
	if (pid == 0)
		child_work(argv, envp, &all);
	else
		wait_childs(all.child_num, pid);
}
