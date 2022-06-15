/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:48:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/13 19:30:11 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	close_unused_fd(t_cmd *cmd, pid_t pid)
{
	if (pid == 0)
	{
		if (cmd->fd[READ] != -2)
			cmd->fd[READ] = ft_close(cmd->fd[READ]);
	}
	else
	{
		if (cmd->fd[WRITE] != -2)
			cmd->fd[WRITE] = ft_close(cmd->fd[WRITE]);
	}
	return ;
}
