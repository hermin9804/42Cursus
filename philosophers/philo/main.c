/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:19:56 by mher              #+#    #+#             */
/*   Updated: 2022/06/25 19:13:39 by mher             ###   ########.fr       */
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
	t_end_state	end_state;
	t_philo		*philos;

	if (parse_args(&info, argc, argv))
		return (exit_with(PARSE_FAIL));
	if (malloc_philos(&philos, &info))
		return (exit_with(MALLOC_FAIL));
	init_philos(philos, &info, &end_state);
	if (init_mutex(philos, &info, &end_state))
	{
		free(philos);
		return (exit_with(MUTEX_FAIL));
	}
	if (run_simulation(philos, &info))
	{
		free(philos);
		destroy_mutex(philos);
		return (RUNTIME_FAIL);
	}
	free(philos);
	destroy_mutex(philos);
	return (exit_with(SUCCESS));
}
