/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 22:08:08 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_arg *arg)
{
	arg->cmd_options = ft_split(arg->argv[arg->proc_cnt], ' ');
	if (arg->cmd_options == NULL)
		error_exit("ft_split fail", EXIT_FAILURE);
	arg->path_cmd = get_path_cmd(arg->path_env, arg->cmd_options[0]);
	if (arg->path_cmd == NULL)
		perror_exit("command not found", 127);
	close_unused_fd(arg);
	if (execve(arg->path_cmd, arg->cmd_options, arg->envp) == -1)
		perror_exit("execve fail", EXIT_FAILURE);
}

static void	parent(t_arg *arg)
{
	if (arg->proc_cnt == arg->argc - 2)
		exit(EXIT_SUCCESS);
	close_unused_fd(arg);
	waitpid(arg->pid, 0, WNOHANG);
	arg->a[READ] = arg->b[READ];
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;

	if (argc < 5)
		error_exit("argument error", EXIT_FAILURE);
	if (pipe(arg.a) < 0)
		perror_exit("pipe error", EXIT_FAILURE);
	init(&arg, argc, argv, envp);
	while (++arg.proc_cnt < argc - 1)
	{
		if (pipe(arg.b) < 0)
			perror_exit("pipe error", EXIT_FAILURE);
		redirect_std_fd(&arg);
		arg.pid = fork();
		if (arg.pid == -1)
			perror_exit("fork error", EXIT_FAILURE);
		else if (arg.pid == 0)
			child(&arg);
		else
			parent(&arg);
	}
	return (0);
}
