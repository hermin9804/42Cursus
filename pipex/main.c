/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/05/03 04:01:42 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	swap_fd(int *a, int *b)
{
	int	tmp[2];

	tmp[0] = a[0];
	tmp[1] = a[1];
	a[0] = b[0];
	a[1] = b[1];
	b[0] = tmp[0];
	b[1] = tmp[1];
}

char	**get_path_envp(char *envp[])
{
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		++envp;
	if (*envp == NULL)
		exit(EXIT_FAILURE); //error_exit();
	path = *envp + 5;
	return (ft_split(path, ':'));
}

static char *get_cmd_argv(char **path, char *proc)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(proc, X_OK);
	if (fd != -1)
		return (proc);
	path_cmd = ft_strjoin("/", proc);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
		i++;
	}
	free(path_cmd);
	return (NULL);
}

void	control_fds(t_arg *arg, int argc)
{
	int	infile_fd;
	int	outfile_fd;

	if (arg->proc_cnt == 2)
	{
		close(arg->b[READ]);
		infile_fd = open(arg->infile, O_RDONLY);
		if (infile_fd == -1)
			exit(EXIT_FAILURE); //error_exit();
		dup2(infile_fd, STDIN_FILENO);
		dup2(arg->b[WRITE], STDOUT_FILENO);
	}
	else if (arg->proc_cnt < argc - 2)
	{
		close(arg->a[WRITE]);
		close(arg->b[READ]);
		dup2(arg->a[READ], STDIN_FILENO);
		dup2(arg->b[WRITE], STDOUT_FILENO);
	}
	else if (arg->proc_cnt == argc - 2)
	{
		close(arg->a[WRITE]);
		outfile_fd = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
			exit(EXIT_FAILURE); //error_exit();
		dup2(arg->a[READ], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
	}
}

void	assign_process(int argc, char *argv[], char *envp[], t_arg *arg)
{
	arg->infile = argv[1];
	arg->outfile = argv[argc - 1];
	arg->path = get_path_envp(envp);
	if (arg->path == 0)
		exit(EXIT_FAILURE); //error_exit();
	arg->cmd = ft_split(argv[arg->proc_cnt], ' ');
	arg->proc = get_cmd_argv(arg->path, arg->cmd[0]);
	if (arg->proc == NULL)
		perror("command not found");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;
	pid_t	child_pid;
	int	i;

	if (argc < 5)
		exit(EXIT_FAILURE); //error_exit();
	if (pipe(arg.a) < 0)
		exit(EXIT_FAILURE); //error_exit();
	if (pipe(arg.b) < 0)
		exit(EXIT_FAILURE); //error_exit();
	i = 2;
	while (i <= argc - 2)
	{
		arg.proc_cnt = i;
		assign_process(argc, argv, envp, &arg);
		child_pid = fork();
		if (child_pid == -1)
			exit(EXIT_FAILURE); //error_exit();
		else if (child_pid == 0)
		{
			control_fds(&arg, argc);
			if (execve(arg.proc, arg.cmd, envp) == -1)
				exit(EXIT_FAILURE); //error_exit();
		}
		else
		{
		//	printf("%d %d\n", i, argc);
			waitpid(child_pid, NULL, WNOHANG);
			swap_fd(arg.a, arg.b);
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}
