/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:02 by mher              #+#    #+#             */
/*   Updated: 2022/05/06 02:36:31 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft/include/libft.h"//
# include "libgnl/include/get_next_line.h"//

typedef struct s_arg
{
	int	argc;
	char	**argv;
	char	**envp;
	char	**path_env;
	char	**cmd_options;
	char	*first_arg;
	char	*last_arg;
	char	*path_cmd;
	pid_t	pid;
	int	proc_cnt;
	int	a[2];
	int	b[2];
	int	o_flag;
}	t_arg;

char	**get_path_env(char *envp[]);
char	*get_path_cmd(char **path_env, char *cmd);

void	init(t_arg *arg, int argc, char *argv[], char *envp[]);

void	close_unused_fd(t_arg *arg);
void	redirect_std_fd(t_arg *arg);

void	perror_exit(const char *error_msg, int exit_code);
void	error_exit(const char *error_msg, int exit_code);

void	handle_error_dup2(int fd1, int fd2);
void	handle_error_close(int fd);
void	handle_error_write(int fd, const char *buff, size_t byte);

void	here_doc(t_arg *arg, char *argv[]);

#endif
