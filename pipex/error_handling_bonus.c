/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:57:12 by mher              #+#    #+#             */
/*   Updated: 2022/05/07 19:56:54 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dup2_handle_error(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit_with_perror("dup2 fail", EXIT_FAILURE);
}

void	close_handle_error(int fd)
{
	if (close(fd) == -1)
		exit_with_perror("close fail", EXIT_FAILURE);
}

void	write_handle_error(int fd, const char *buff, size_t byte)
{
	if (write(fd, buff, byte) == -1)
		exit_with_perror("write fail", EXIT_FAILURE);
}

void	exit_with_perror(const char *error_msg, int exit_code)
{
	perror(error_msg);
	exit(exit_code);
}
