/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:19:56 by mher              #+#    #+#             */
/*   Updated: 2022/06/19 02:34:46 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static enum	e_exit_status exit_with(enum e_exit_status exit_status)
{
	const char	*err_msg[] = \
	{
		"",
		"Usage : ./philo nop ttd tte tts [nome]\n",
		"Error : Failed to memory alloc\n",
		"Error : Failed to init mutex\n",
		"Error : Runtime Error\n"
	};

	if (exit_status == SUCCESS)
		return (SUCCESS);
	write(STDERR_FILENO, err_msg[exit_status], ft_strlen(err_msg[exit_status]));
	return (exit_status);
}

int	main(int argc, char *argv[])
{
	t_info		info;
	t_philo		*philo;
	t_shared	shared_var;

	if (parse_args(&info, argc, argv))
		return (exit_with(PARSE_FAIL));
	if (alloc_philo(philo, &info))
		return (exit_with(ALLOC_FAIL));
	init_philo(philo, &info);
	if (init_mutex(philo, &shared_var, &info))
		return (exit_with(MUTEX_FAIL));
	return (exit_with(SUCCESS));
}