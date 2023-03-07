/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:16:42 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/26 16:17:09 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_all
{
	int	child_num;
	int	child_idx;
	int	left_fds[2];
	int	right_fds[2];
}	t_all;

//parse.c || parse2.c
char	**parse_cmd(char *cmd);
char	**free_parse_arr(char **str_arr, int num);

//path.c
char	**get_path(char **envp);
void	exe_if_possible(char **parsed_cmd, char **path, char *envp[]);

//check_err.c
void	check_pipe(int *fds);
int		check_fork(void);
void	check_close(int fd);
int		check_dup2(int fd1, int fd2);
void	check_open_fd(char *path, int fd);

//check_err2.c
char	*check_malloc(char *addr);
char	**check_malloc2(char **addr);

//parent.c
void	wait_childs(int child_num);

//child.c
void	child_work(char *argv[], char *envp[], t_all *all);

#endif
