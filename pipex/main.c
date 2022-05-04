/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 04:29:51 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_env(char *envp[])
{
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		++envp;
	if (*envp == NULL)
		exit(EXIT_FAILURE); //error_exit();
	path = *envp + 5;
	return (ft_split(path, ':'));
}

static char *get_path_cmd(char **path_env, char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	path_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (path_env[i])
	{
		tmp = ft_strjoin(path_env[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd == 0)
		{
			free(path_cmd);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

void	redirect_std_fileno(t_arg *arg)
{
	if (arg->proc_cnt == 2)
	{
		dup2(arg->in_fd, STDIN_FILENO);
		dup2(arg->b[WRITE], STDOUT_FILENO);
	}
	else if (arg->proc_cnt == arg->argc - 2)
	{
		dup2(arg->a[READ], STDIN_FILENO);
		dup2(arg->out_fd, STDOUT_FILENO);
	}
	else if (arg->proc_cnt < arg->argc - 2)
	{
		dup2(arg->a[READ], STDIN_FILENO);
		dup2(arg->b[WRITE], STDOUT_FILENO);
	}
}

void	close_unused_fd(t_arg *arg)
{
	int	unused_a;
	int	unused_b;

	if (arg->pid == 0)
	{
		unused_a = WRITE;
		unused_b = READ;
	}
	else
	{
		unused_a = READ;
		unused_b = WRITE;
	}
	close(arg->a[unused_a]);
	close(arg->b[unused_b]);
}

void	child(t_arg *arg)
{
	char	**cmd_options;
	char	*path_cmd;

	cmd_options = ft_split(arg->argv[arg->proc_cnt], ' ');
	if (cmd_options == NULL)
		exit(EXIT_FAILURE); //error_exit();
	path_cmd = get_path_cmd(arg->path_env, cmd_options[0]);
	if (path_cmd == NULL)
		perror("command not found");
	close_unused_fd(arg);
	if (execve(path_cmd, cmd_options, arg->envp) == -1)
		exit(EXIT_FAILURE); //error_exit();
}

void	parent(t_arg *arg)
{
	if (arg->proc_cnt == arg->argc - 2) // 해야 될듯?
		exit(EXIT_SUCCESS);
	close_unused_fd(arg);
	waitpid(arg->pid, 0, WNOHANG);
	arg->a[READ] = arg->b[READ];
}

void	init(t_arg *arg, int argc, char *argv[], char *envp[])
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	arg->path_env = get_path_env(envp);
	if (arg->path_env == 0)
		exit(EXIT_FAILURE); //error_exit();
	arg->in_fd = open(argv[1], O_RDONLY);
	if (arg->in_fd == -1)
		exit(EXIT_FAILURE); //error_exit();
	arg->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->out_fd == -1)
		exit(EXIT_FAILURE); //error_exit();
	arg->proc_cnt = 1;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;

	if (argc < 5)
		exit(EXIT_FAILURE); //error_exit();
	if (pipe(arg.a) < 0)
		exit(EXIT_FAILURE); //error_exit();
	init(&arg, argc, argv, envp);
	while (++arg.proc_cnt < argc - 1)
	{
		if (pipe(arg.b) < 0)
			exit(EXIT_FAILURE); //error_exit();
		redirect_std_fileno(&arg);
		arg.pid = fork();
		if (arg.pid == -1)
			exit(EXIT_FAILURE); //error_exit();
		else if (arg.pid == 0)
			child(&arg);
		else
			parent(&arg);
	}
	exit(EXIT_FAILURE); //error_exit();
}
