/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:14:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/08 17:24:26 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"

static int	is_all_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	exit_no_arg(t_cmd *cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (cmd->prev == NULL)
		ft_write(STDOUT_FILENO, "exit\n", 5);
	exit(exit_code);
}

static void	exit_two_arg(t_cmd *cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (cmd->prev == NULL)
		ft_write(STDOUT_FILENO, "exit\n", 5);
	if (!is_all_number(cmd->argv[1]))
	{
		print_err3("exit", cmd->argv[1], "numeric argument required");
		exit_code = 255;
	}
	else
		exit_code = ft_atoi(cmd->argv[1]) % 256;
	exit(exit_code);
}

int	ft_exit(t_cmd *cmd)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (cmd->argc == 1)
		exit_no_arg(cmd);
	if (cmd->argc == 2)
		exit_two_arg(cmd);
	if (cmd->argc > 2)
	{
		if (!is_all_number(cmd->argv[1]))
			exit_code = 255;
		if (cmd->prev == NULL && exit_code == 255)
		{
			ft_write(STDOUT_FILENO, "exit\n", 5);
			print_err3("exit", cmd->argv[1], "numeric argument required");
			exit(exit_code);
		}
	}
	ft_write(STDOUT_FILENO, "exit\n", 5);
	print_err3("exit", NULL, "too many arguments");
	return (0);
}
