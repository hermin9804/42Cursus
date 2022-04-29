/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:37:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/29 18:15:46 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
	char *args[] = {"/bin/echo", "hello", NULL};
	printf("I'm child! my pid is %d.\n", getpid());
	fflush(stdout);
	execve("/bin/echo", args, NULL);
	err(EXIT_FAILURE, "exec() failed");
}

static void parent(pid_t pid_c)
{
	printf("I'm parent! my pid is %d and of my child is %d.\n", getpid(), pid_c);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	pid_t	ret;
	int	fdA[2];
	int	fdB[2];
	
	if (pipe(fdA) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	if (pipe(fdB) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	ret = fork();
	if (ret == -1)
		err(EXIT_FAILURE, "fork() failed");
	if (ret == 0)
		child();
	else
		parent(ret);
	err(EXIT_FAILURE, "shouldn't reach here");
}
