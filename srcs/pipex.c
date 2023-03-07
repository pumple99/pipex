/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:17:32 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/26 17:26:06 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // close
#include "../pipex.h" //...
#include "../libft/libft.h" //ft_strncmp ft_strput_fd

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

int	heredoc_main(int argc, char *argv[], char *envp[])
{
	if (argc < 6)
		return (ft_putstr_fd("here_doc needs more than 4 arguments\n", 2));
	if (envp[0] == argv[0])
		return (0);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_all	all;
	pid_t	pid;

	if (argc < 5)
		return (ft_putstr_fd("pipex needs more than 3 arguments\n", 2));
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
		wait_childs(all.child_num);
}
