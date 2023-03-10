/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:16:42 by seunghoy          #+#    #+#             */
/*   Updated: 2023/03/10 19:02:18 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define HEREDOC_TEMP ".here_doc_tmp"

typedef struct s_all
{
	int		child_num;
	int		child_idx;
	int		left_fds[2];
	int		right_fds[2];
	char	**path;
}	t_all;

//parse.c || parse2.c
int		get_new_state(int prev_state, char c);
char	**parse_cmd(char *cmd);
char	**free_parse_arr(char **str_arr, int num);

//path.c
char	**get_path(char **envp);
void	exe_if_possible(char **parsed_cmd, char **path, char *envp[]);

//parent.c
void	wait_childs(int child_num, int last_child_pid);
void	wait_childs_heredoc(int child_num, int last_child_pid);

//child.c
void	child_work(char *argv[], char *envp[], t_all *all);
void	work(char *argv[], char *envp[], t_all *all);

//child_heredoc.c
void	child_work_heredoc(char *argv[], char *envp[], t_all *all);

//check_err.c
void	check_pipe(int *fds);
int		check_fork(void);
void	check_close(int fd);
int		check_dup2(int fd1, int fd2);
void	check_open_fd(char *path, int fd);

//check_err2.c
char	*check_malloc(char *addr);
char	**check_malloc2(char **addr);
char	*check_gnl(char *gnl_line);
int		check_access(char *path);

//error.c
int		err_exit(char *str);

#endif
