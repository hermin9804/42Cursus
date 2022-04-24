/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:23:58 by mher              #+#    #+#             */
/*   Updated: 2022/04/24 18:37:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	length;
	int	fd[2];
	int	pid;
	char	msg[100] = "I'm ur child";
	char	line[100];

	pipe(fd);
	if ((pid = fork()) == 0)
	{
		close(fd[0]);
		printf("%s\n", msg);
		length = strlen(msg) + 1;
		write(fd[1], msg, length);
		printf("PID %d sent -> %s\n", getpid(), msg);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], line, 100))
		{
			printf("PID %d received -> %s\n", getpid(), line);
		}
	}
	return (0);
}
