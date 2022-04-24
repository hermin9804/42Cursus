/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:23:58 by mher              #+#    #+#             */
/*   Updated: 2022/04/24 22:31:20 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 자식 프로세스에서 부모 프로세스로 "I'm ur child"를 보내기

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	fd[2];
	int	pid;
	char	msg[100] = "I'm ur child";
	char	line[100];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], msg, strlen(msg) + 1);
		printf("PID %d sent     -> %s\n", getpid(), msg);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], line, 100))
			printf("PID %d received -> %s\n", getpid(), line);
	}
	exit(0);
}
