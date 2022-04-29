/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/29 19:26:18 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "pipex.h"

static void child(int fd[2])
{
	dup2(fd[FD_OUT], STDOUT_FILENO);
	char *args[] = {"/bin/echo", "hello", NULL};
	printf("I'm child!\n");
	fflush(stdout);
	execve("/bin/echo", args, NULL);
	err(EXIT_FAILURE, "exec() failed");
}

static void parent(int fd[2])
{
	char tmp[5];
	int	cnt;

	printf("I'm parent!\n");
	cnt = read(fd[FD_IN], tmp, 5);
	printf("%d\n", cnt);
	write(STDOUT_FILENO, tmp, 5);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	child_pid;
	int	fd[2];
	int	status;

	(void)argv;
	(void)envp;
	if (argc < 1)
		return (0);
	if (pipe(fd) < 0)
	{
		printf("pipe error\n");
		exit(EXIT_FAILURE);
	}
	child_pid = fork();
	if (child_pid == -1)
		err(EXIT_FAILURE, "fork() failed");
	if (child_pid == 0)
	{
		child(fd);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		parent(fd);
	}
	err(EXIT_FAILURE, "shouldn't reach here");
}
