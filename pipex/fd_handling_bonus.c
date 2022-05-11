/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handling_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:12:41 by mher              #+#    #+#             */
/*   Updated: 2022/05/08 01:22:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirect_std_fd(t_arg *arg)
{
	int	fd;

	if (arg->proc_cnt == 2)
	{
		fd = open(arg->first_arg, O_RDONLY);
		if (fd == -1)
			exit_with_perror("infile open fail", EXIT_FAILURE);
		dup2_handle_error(fd, STDIN_FILENO);
		dup2_handle_error(arg->b[WRITE], STDOUT_FILENO);
	}
	else if (arg->proc_cnt == arg->argc - 2)
	{
		fd = open(arg->last_arg, arg->o_flag, 0644);
		if (fd == -1)
			exit_with_perror("outfile open fail", EXIT_FAILURE);
		dup2_handle_error(arg->a[READ], STDIN_FILENO);
		dup2_handle_error(fd, STDOUT_FILENO);
	}
	else if (arg->proc_cnt < arg->argc - 2)
	{
		dup2_handle_error(arg->a[READ], STDIN_FILENO);
		dup2_handle_error(arg->b[WRITE], STDOUT_FILENO);
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
	close_handle_error(arg->a[unused_a]);
	close_handle_error(arg->b[unused_b]);
}
