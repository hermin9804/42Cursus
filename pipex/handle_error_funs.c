/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_funs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:57:12 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 23:00:57 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		perror_exit("dup2 fail", EXIT_FAILURE);
}

void	handle_error_close(int fd)
{
	if (close(fd) == -1)
		perror_exit("close fail", EXIT_FAILURE);
}

void	handle_error_write(int fd, char *buff, size_t byte)
{
	if (write(fd, buff, byte) == -1)
		perror_exit("write fail", EXIT_FAILURE);
}
