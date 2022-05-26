/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:02 by mher              #+#    #+#             */
/*   Updated: 2022/05/26 18:38:36 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../lib/libft/include/libft.h"
# include "../lib/libgnl/include/get_next_line.h"

typedef struct s_arg
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**path_env;
	char	**cmd_options;
	char	*first_arg;
	char	*last_arg;
	char	*path_cmd;
	int		proc_cnt;
	int		a[2];
	int		b[2];
	int		o_flag;
	pid_t	pid;
}	t_arg;

char	**get_path_env(char *envp[]);
char	*get_path_cmd(char **path_env, char *cmd);
void	close_unused_fd(t_arg *arg);
void	redirect_std_fd(t_arg *arg);
void	exit_with_perror(const char *error_msg, int exit_code);
void	dup2_handle_error(int fd1, int fd2);
void	close_handle_error(int fd);
void	write_handle_error(int fd, const char *buff, size_t byte);
void	here_doc(t_arg *arg);

#endif
