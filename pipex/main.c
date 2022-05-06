/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/05/07 08:32:17 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	here_doc(t_arg *arg, char *argv[])
{
	char	*line;
	char	*lim;
	size_t	len;

	if (ft_strlen(argv[1]) != 8 || ft_strncmp(argv[1], "here_doc", 8))
		return ;
	if (pipe(arg->b) < 0)
		perror_exit("pipe fail", EXIT_FAILURE);
	lim = argv[2];
	len = ft_strlen(lim);
	arg->pid = fork();
	if (arg->pid == 0)
	{
		while (1)
		{
			handle_error_write(STDOUT_FILENO, "pipe heredoc> ", 14);
			line = get_next_line(STDIN_FILENO);
			if (ft_strlen(line) - 1 == len && !ft_strncmp(line, lim, len))
			{
				free(line);
				break ;
			}
			handle_error_write(arg->b[WRITE], line, ft_strlen(line));
			free(line);
		}
		close_unused_fd(arg);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close_unused_fd(arg);
		arg->a[READ] = arg->b[READ];
	}
	arg->o_flag = O_WRONLY | O_CREAT | O_APPEND;
	arg->proc_cnt = 3;
}


void	child(t_arg *arg)
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

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;

	if (argc < 5)
		error_exit("wrong argument input error", EXIT_FAILURE);
	if (pipe(arg.a) < 0)
		perror_exit("pipe fail", EXIT_FAILURE);
	init(&arg, argc, argv, envp);
	here_doc(&arg, argv);
	while (arg.proc_cnt < argc - 1)
	{
		if (pipe(arg.b) < 0)
			perror_exit("pipe fail", EXIT_FAILURE);
		redirect_std_fd(&arg);
		arg.pid = fork();
		if (arg.pid == -1)
			perror_exit("fork fail", EXIT_FAILURE);
		else if (arg.pid == 0)
			child(&arg);
		else
		close_unused_fd(&arg);
		arg.a[READ] = arg.b[READ];
		arg.proc_cnt++;
	}
	while (waitpid(0, 0, WNOHANG) != -1);
	exit(EXIT_SUCCESS);
}
