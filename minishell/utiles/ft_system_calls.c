/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_system_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:25:40 by mher              #+#    #+#             */
/*   Updated: 2022/06/13 19:23:50 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utiles.h"

int	ft_open(char *fname, int oflag, int mode)
{
	int	fd;

	fd = open(fname, oflag, mode);
	if (fd < 0)
		exit_with_err(fname, strerror(errno), EXIT_FAILURE);
	return (fd);
}

int	ft_close(int fd)
{
	if (close(fd) == -1)
		exit_with_err("close()", strerror(errno), EXIT_FAILURE);
	return (-2);
}

void	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit_with_err("dup2()", strerror(errno), EXIT_FAILURE);
}

void	ft_pipe(int *fds)
{
	if (pipe(fds) == -1)
		exit_with_err("pipe()", strerror(errno), EXIT_FAILURE);
}

pid_t	ft_fork(void)
{
	int	ret;

	ret = fork();
	if (ret < 0)
		exit_with_err("fork()", strerror(errno), EXIT_FAILURE);
	return (ret);
}
