/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:12:41 by mher              #+#    #+#             */
/*   Updated: 2022/05/06 01:46:39 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_std_fd(t_arg *arg)
{
	int	fd;

	if (arg->proc_cnt == 2)
	{
		fd = open(arg->first_arg, O_RDONLY);
		if (fd == -1)
			perror_exit("open fail", EXIT_FAILURE);
		handle_error_dup2(fd, STDIN_FILENO);
		handle_error_dup2(arg->b[WRITE], STDOUT_FILENO);
	}
	else if (arg->proc_cnt == arg->argc - 2)
	{
		fd = open(arg->last_arg, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			perror_exit("open fail", EXIT_FAILURE);
		handle_error_dup2(arg->a[READ], STDIN_FILENO);
		handle_error_dup2(fd, STDOUT_FILENO);
	}
	else if (arg->proc_cnt < arg->argc - 2)
	{
		handle_error_dup2(arg->a[READ], STDIN_FILENO);
		handle_error_dup2(arg->b[WRITE], STDOUT_FILENO);
	}
}

void	close_unused_fd(t_arg *arg)
{
	int	unused_a;
	int	unused_b;

	if (arg->pid == 0)
	{
		unused_a = WRITE;
		unused_b = READ;
	}
	else
	{
		unused_a = READ;
		unused_b = WRITE;
	}
	handle_error_close(arg->a[unused_a]);
	handle_error_close(arg->b[unused_b]);
}
