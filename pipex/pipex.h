/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:02 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 17:46:44 by mher             ###   ########.fr       */
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
# include <errno.h>

# include "libft/include/libft.h"//

typedef struct s_arg
{
	int	argc;
	char	**argv;
	char	**envp;
	char	**path_env;
	int	in_fd;
	int	out_fd;
	int	proc_cnt;
	pid_t	pid;
	int	a[2];
	int	b[2];
	char	**cmd_options;
	char	*path_cmd;
}	t_arg;

#endif

char	**get_path_env(char *envp[]);
char	*get_path_cmd(char **path_env, char *cmd);

void	init(t_arg *arg, int argc, char *argv[], char *envp[]);

void	close_unused_fd(t_arg *arg);
void	redirect_std_fd(t_arg *arg);

void	perror_exit(char *error_msg);
void	error_exit(char *error_msg);

