/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/05/08 03:38:43 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// print arg.a, arg.b
static void	test(t_arg *arg)
{
	char tmp[5];

	sprintf(tmp, "%d %d\n", arg->a[0], arg->a[1]);
	write(2, tmp, 4);
	sprintf(tmp, "%d %d\n", arg->b[0], arg->b[1]);
	write(2, tmp, 4);
}

static void	init(t_arg *arg, int argc, char *argv[], char *envp[])
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	arg->first_arg = argv[1];
	arg->last_arg = argv[argc - 1];
	arg->path_env = get_path_env(envp);
	if (arg->path_env == 0)
		exit_with_perror("PATH not found", EXIT_FAILURE);
	arg->proc_cnt = 2;
	arg->o_flag = O_RDWR | O_CREAT | O_TRUNC;
}

static void	execute(t_arg *arg)
{
	arg->cmd_options = ft_split(arg->argv[arg->proc_cnt], ' ');
	if (arg->cmd_options == NULL)
		exit_with_perror("ft_split fail", EXIT_FAILURE);
	arg->path_cmd = get_path_cmd(arg->path_env, arg->cmd_options[0]);
	if (arg->path_cmd == NULL)
		exit_with_perror("command not found", 127);
	close_unused_fd(arg);
	if (execve(arg->path_cmd, arg->cmd_options, arg->envp) == -1)
		exit_with_perror("execve fail", EXIT_FAILURE);
}

static void	fork_and_exec(t_arg *arg)
{
	while (arg->proc_cnt < arg->argc - 1)
	{
		if (pipe(arg->b) < 0)
			exit_with_perror("pipe fail", EXIT_FAILURE);
		redirect_std_fd(arg);
		test(arg);
		arg->pid = fork();
		if (arg->pid == -1)
			exit_with_perror("fork fail", EXIT_FAILURE);
		else if (arg->pid == 0)
			execute(arg);
		else
		{
			close_unused_fd(arg);
			arg->a[READ] = arg->b[READ];
			arg->proc_cnt++;
		}
	}
}

static void	wait_childs(void)
{
	while (wait(0) != -1)
		;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;

	if (argc < 5)
		exit_with_perror("wrong argument input error", EXIT_FAILURE);
	if (pipe(arg.a) < 0)
		exit_with_perror("pipe fail", EXIT_FAILURE);
	init(&arg, argc, argv, envp);
	here_doc(&arg);
	fork_and_exec(&arg);
	wait_childs();
	exit(EXIT_SUCCESS);
}
