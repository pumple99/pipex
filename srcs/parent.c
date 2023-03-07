/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:20:03 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/07 17:20:06 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <stdio.h> //perror

void	wait_childs(int child_num)
{
	int		idx;
	pid_t	pid;

	idx = -1;
	while (++idx < child_num)
	{
		pid = wait(0);
		if (pid == -1)
		{
			perror("bash: wait failed");
			exit(EXIT_FAILURE);
		}
	}
}
