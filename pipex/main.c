/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 17:43:58 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_arg *arg)
{
	arg->cmd_options = ft_split(arg->argv[arg->proc_cnt], ' ');
	if (arg->cmd_options == NULL)
		error_exit("fail");
	arg->path_cmd = get_path_cmd(arg->path_env, arg->cmd_options[0]);
	if (arg->path_cmd == NULL)
		perror_exit("can't find command");
	close_unused_fd(arg);
	if (execve(arg->path_cmd, arg->cmd_options, arg->envp) == -1)
		perror_exit("can't execute command");
}

static void	parent(t_arg *arg)
{
	if (arg->proc_cnt == arg->argc - 2) // 해야 될듯?
		exit(EXIT_SUCCESS);
	close_unused_fd(arg);
	waitpid(arg->pid, 0, WNOHANG);
	arg->a[READ] = arg->b[READ];
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
		redirect_std_fd(&arg);
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
