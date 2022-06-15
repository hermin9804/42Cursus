/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:08:04 by mher              #+#    #+#             */
/*   Updated: 2022/06/14 15:40:27 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <readline/readline.h>

# include "../struct/struct.h"
# include "../utiles/utiles.h"
# include "../builtins/builtin.h"

void	executor(t_cmd *cmd, t_env *env_head, char *envp[]);
void	redirect(t_cmd *cmd);
int		heredoc(t_cmd *cmd);
void	close_unused_fd(t_cmd *cmd, pid_t pid);
int		check_valid_syntax(t_cmd *cmd_head);
void	wait_child(void);
int		is_need_fork(t_cmd *cmd);
void	restore_redirection_char(t_cmd *cmd);

char	*get_cmd_path(t_cmd *cmd, t_env *env_head);

int		io_file_open(t_cmd *cmd, t_env *env_head);
void	trim_cmd_argv(t_cmd *cmd, const char *set, int direction);

char	*get_tmp_file_name(void);
void	delete_tmp_file(void);
int		init_heredoc(t_cmd *cmd);
void	clear_cmd(t_cmd *cmd_head);

#endif
