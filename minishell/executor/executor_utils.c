/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:45:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/14 15:40:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	is_need_fork(t_cmd *cmd)
{
	if (cmd->prev != NULL)
		return (1);
	if (cmd->is_pipe == true)
		return (1);
	if (cmd->infile != -2)
		return (1);
	if (cmd->outfile != -2)
		return (1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "exit"))
		return (0);
	return (1);
}

void	restore_redirection_char(t_cmd *cmd)
{
	int		i;
	int		j;

	i = 0;
	while (cmd->argv[i])
	{
		j = 0;
		while (cmd->argv[i][j])
		{
			if (cmd->argv[i][j] == -74)
				cmd->argv[i][j] = '<';
			else if (cmd->argv[i][j] == -76)
				cmd->argv[i][j] = '>';
			++j;
		}
		++i;
	}
}
