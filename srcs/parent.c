/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:20:03 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/12 18:01:20 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <unistd.h> //unlink
#include "../pipex.h" //perr_exit
#include "../pipex_consts.h" //HEREDOC_TEMP

static void	set_exit_status(int child_status, int *exit_status)
{
	int	status;

	status = 0;
	if (WIFEXITED(child_status))
		status = WEXITSTATUS(child_status);
	else if (WIFSIGNALED(child_status))
		status = WTERMSIG(child_status);
	else if (WIFSTOPPED(child_status))
		status = WSTOPSIG(child_status);
	*exit_status = status;
}

void	wait_childs(int child_num, int last_child_pid)
{
	int		idx;
	pid_t	pid;
	int		status;
	int		exit_status;

	idx = -1;
	exit_status = 0;
	status = 0;
	while (++idx < child_num)
	{
		pid = wait(&status);
		if (pid == -1)
			perr_exit("bash: wait failed", EXIT_FAILURE);
		else if (pid == last_child_pid)
			set_exit_status(status, &exit_status);
	}
	exit(exit_status);
}

void	wait_childs_heredoc(int child_num, int last_child_pid)
{
	int		idx;
	pid_t	pid;
	int		status;
	int		exit_status;

	idx = -1;
	exit_status = 0;
	status = 0;
	while (++idx < child_num)
	{
		pid = wait(&status);
		if (pid == -1)
			perr_exit("bash: wait failed", EXIT_FAILURE);
		else if (pid == last_child_pid)
			set_exit_status(status, &exit_status);
	}
	unlink(HEREDOC_TEMP);
	exit(exit_status);
}
