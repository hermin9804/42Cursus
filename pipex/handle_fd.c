/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:12:41 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 22:58:37 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_std_fd(t_arg *arg)
{
	if (arg->proc_cnt == 2)
	{
		handle_error_dup2(arg->in_fd, STDIN_FILENO);
		handle_error_dup2(arg->b[WRITE], STDOUT_FILENO);
	}
	else if (arg->proc_cnt == arg->argc - 2)
	{
		handle_error_dup2(arg->a[READ], STDIN_FILENO);
		handle_error_dup2(arg->out_fd, STDOUT_FILENO);
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
