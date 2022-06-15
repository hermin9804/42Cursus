/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:55:25 by mher              #+#    #+#             */
/*   Updated: 2022/06/14 15:19:36 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	check_alone_pipe(t_cmd *cmd)
{
	if (cmd->is_pipe && cmd->argc == 0)
	{
		print_err("syntax error near unexpected token `|'");
		g_exit_code = 258;
		return (-1);
	}
	return (0);
}

static int	check_redirection_file(t_cmd *cmd, int i, int ret)
{
	const char	oc[2] = {-76, '\0'};
	const char	oa[3] = {-76, -76, '\0'};
	const char	ic[2] = {-74, '\0'};
	const char	ia[3] = {-74, -76, '\0'};

	if (cmd->argc == 0)
		return (0);
	while (i < cmd->argc)
	{
		if (!ft_strcmp(cmd->argv[i], oc) || !ft_strcmp(cmd->argv[i], oa))
			if (cmd->argv[i + 1] == NULL || ft_strlen(cmd->argv[i + 1]) == 0)
				ret = -1;
		if (!ft_strcmp(cmd->argv[i], ic) || !ft_strcmp(cmd->argv[i], ia))
			if (cmd->argv[i + 1] == NULL || ft_strlen(cmd->argv[i + 1]) == 0)
				ret = -1;
		if (ret == -1)
		{
			print_err("syntax error near unexpected token `newline'");
			g_exit_code = 258;
			return (-1);
		}
		++i;
	}
	return (0);
}

static int	check_empty_cmd(t_cmd *cmd)
{
	if (cmd->is_dollar == false && cmd->argc == 1 && \
			!ft_strcmp(cmd->argv[0], ""))
	{
		print_err2("", "command not found");
		g_exit_code = 127;
		return (-1);
	}
	return (0);
}

int	check_valid_syntax(t_cmd *cmd_head)
{
	t_cmd	*cur;

	cur = cmd_head;
	if (cur->argc == 0)
		return (-1);
	if (check_alone_pipe(cmd_head) == -1)
		return (-1);
	while (cur)
	{
		if (check_empty_cmd(cur) == -1)
			return (-1);
		else if (check_redirection_file(cur, 0, 0) == -1)
			return (-1);
		cur = cur->next;
	}
	return (0);
}
