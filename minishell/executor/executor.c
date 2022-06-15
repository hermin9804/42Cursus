/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:46:29 by mher              #+#    #+#             */
/*   Updated: 2022/06/14 15:40:33 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	os_builtins(t_cmd *cmd, t_env *env_head, char *envp[])
{
	char	*env_path;

	env_path = ft_getenv(env_head, "PATH");
	if (env_path == NULL && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (env_path != NULL && ft_strlen(env_path) == 0 && cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "No such file or directory");
		return (127);
	}
	if (cmd->cmd_path == NULL)
	{
		print_err3(cmd->argv[0], NULL, "command not found");
		return (127);
	}
	ft_execve(cmd->cmd_path, cmd->argv, envp);
	return (EXIT_FAILURE);
}

static int	execute_cmd(t_cmd *cmd, t_env *env_head, char *envp[])
{
	restore_redirection_char(cmd);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (ft_echo(cmd->argc, cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (ft_cd(cmd->argv[1], env_head));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (ft_export(cmd->argc, cmd->argv, env_head));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (ft_unset(cmd->argc, cmd->argv, env_head));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (ft_env(env_head));
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (ft_exit(cmd));
	return (os_builtins(cmd, env_head, envp));
}

static void	do_fork_cmd(t_cmd *cmd, t_env *env_head, char *envp[])
{
	pid_t	pid;
	int		exit_code;

	set_signal(DFL, DFL);
	pid = ft_fork();
	if (pid == 0)
	{
		redirect(cmd);
		close_unused_fd(cmd, pid);
		exit_code = execute_cmd(cmd, env_head, envp);
		exit (exit_code);
	}
	else
	{
		close_unused_fd(cmd, pid);
		set_signal(IGN, IGN);
	}
	return ;
}

static void	do_cmd(t_cmd *cmd, t_env *env_head, char *envp[])
{
	g_exit_code = execute_cmd(cmd, env_head, envp);
	close_unused_fd(cmd, 1);
}

void	executor(t_cmd *cmd_head, t_env *env_head, char *envp[])
{
	t_cmd	*cmd_cur;

	cmd_cur = cmd_head;
	if (check_valid_syntax(cmd_head) == -1)
		return (clear_cmd(cmd_head));
	if (init_heredoc(cmd_cur) == -1)
		return (clear_cmd(cmd_head));
	while (cmd_cur)
	{
		if (io_file_open(cmd_cur, env_head) == -1)
		{
			cmd_cur = cmd_cur->next;
			continue ;
		}
		if (is_need_fork(cmd_cur) == true)
			do_fork_cmd(cmd_cur, env_head, envp);
		else
			do_cmd(cmd_cur, env_head, envp);
		cmd_cur = cmd_cur->next;
	}
	wait_child();
	set_signal(SHE, SHE);
	return (clear_cmd(cmd_head));
}
