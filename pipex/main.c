/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/30 02:53:21 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//static void child(t_arg *arg, char *envp[])
//{
//	close(arg->pipe[READ]);
//	dup2(arg->infile, STDIN_FILENO);
//	dup2(arg->pipe[WRITE], STDOUT_FILENO);
//	execve(arg->cmd1, arg->cmd_arg1, envp);
//	exit(EXIT_FAILURE); //error_exit();
//}
//
//static void parent(t_arg *arg, char *envp[])
//{
//	waitpid(arg->child_pid, NULL, WNOHANG);
//	close(arg->pipe[WRITE]);
//	dup2(arg->pipe[READ], STDIN_FILENO);
//	dup2(arg->outfile, STDOUT_FILENO);
//	execve(arg->cmd2, arg->cmd_arg2, envp);
//	exit(EXIT_SUCCESS);
//}

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

static char *get_cmd_argv(char **path, char *cmd)
{
	int		i;
	int		fd;
	char	*path_cmd;
	char	*tmp;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	path_cmd = ft_strjoin("/", cmd);
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

static void parse_arg(t_arg *arg, char *argv[], char *envp[])
{
	arg->infile = open(argv[1], O_RDONLY);
	if (arg->infile == -1)
		perror("infile");
	arg->outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->outfile == -1)
		exit(EXIT_FAILURE); //error_exit();
	arg->path = get_path_envp(envp);
	if (arg->path == 0)
		exit(EXIT_FAILURE); //error_exit();
	arg->cmd_arg1 = ft_split(argv[2], ' ');
	arg->cmd_arg2 = ft_split(argv[3], ' ');
	arg->cmd1 = get_cmd_argv(arg->path, arg->cmd_arg1[0]);
	arg->cmd2 = get_cmd_argv(arg->path, arg->cmd_arg2[0]);
	if (arg->cmd1 == NULL || arg->cmd2 == NULL)
		perror("command not found");
}

void	control_fds(int closed, int std_in, int std_out)
{
	close(closed);
	if (dup2(std_in, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE); //error_exit();
	if (dup2(std_out, STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE); //error_exit();
	close(std_in);
	close(std_out);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;

	if (argc != 5)
		exit(EXIT_FAILURE); //error_exit();
	parse_arg(&arg, argv, envp);
	if (pipe(arg.pipe) < 0)
		exit(EXIT_FAILURE); //error_exit();
	arg.child_pid = fork();
	if (arg.child_pid == -1)
		exit(EXIT_FAILURE); //error_exit();
	else if (arg.child_pid == 0)
	{
		control_fds(arg.pipe[0], arg.infile, arg.pipe[1]);
		if (execve(arg.cmd1, arg.cmd_arg1, envp) == -1)
			exit(EXIT_FAILURE); //error_exit();
	}
	else
	{
		control_fds(arg.pipe[1], arg.pipe[0], arg.outfile);
		waitpid(arg.child_pid, NULL, WNOHANG);
		if (execve(arg.cmd2, arg.cmd_arg2, envp) == -1)
			exit(EXIT_FAILURE); //error_exit();
	}
	exit(0);
}
