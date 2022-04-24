/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:57:55 by mher              #+#    #+#             */
/*   Updated: 2022/04/24 22:57:58 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFF 1024
#define READ 0
#define WRITE 1

int	main(void)
{
	int	fd[2];
	pid_t	pid;
	char	buff[MAX_BUFF];

	if (pipe(fd) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	if (pid > 0) // parent process
	{
		close(fd[READ]);
		strcpy(buff, "message from parent");
		write(fd[WRITE], buff, strlen(buff) + 1);
	}
	else // child process
	{
		close(fd[WRITE]);
		read(fd[READ], buff, MAX_BUFF);
		printf("child got message : %s\n", buff);
	}
	exit(0);
}
