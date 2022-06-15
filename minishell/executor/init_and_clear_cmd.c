/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_clear_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:40:14 by mher              #+#    #+#             */
/*   Updated: 2022/06/14 14:41:58 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	init_heredoc(t_cmd *cmd)
{
	t_cmd	*cur;

	cur = cmd;
	while (cur)
	{
		if (heredoc(cur) == -1)
			return (-1);
		cur = cur->next;
	}
	return (0);
}

void	clear_cmd(t_cmd *cmd_head)
{
	t_cmd	*cur;

	cur = cmd_head;
	while (cur)
	{
		if (cur->fd[READ] > 0)
			ft_close(cur->fd[READ]);
		if (cur->infile > 0)
			ft_close(cur->infile);
		if (cur->outfile > 0)
			ft_close(cur->outfile);
		if (cur->cmd_path != NULL)
			cur->cmd_path = ft_free(cur->cmd_path);
		cur = cur->next;
	}
	delete_tmp_file();
}
