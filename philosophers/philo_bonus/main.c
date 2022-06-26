/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:19:56 by mher              #+#    #+#             */
/*   Updated: 2022/06/26 15:17:26 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static enum	e_exit_status exit_with(enum e_exit_status exit_status)
{
	const char	*err_msg[] = \
	{
		"",
		"Usage : ./philo nop ttd tte tts [nome]\n",
		"Error : Failed to init semaphore\n",
		"Error : Runtime Error\n"
	};

	if (exit_status == SUCCESS)
		return (SUCCESS);
	write(STDERR_FILENO, err_msg[exit_status], ft_strlen(err_msg[exit_status]));
	return (exit_status);
}

int	main(int argc, char *argv[])
{
	t_philo		philo;
	t_info		info;
	t_shared	shared;

	if (parse_args(&info, argc, argv))
		return (exit_with(PARSE_FAIL));
	if (init_semaphore(&shared, &info))
		return (exit_with(SEMAPHORE_FAIL));
	memset(&philo, 0, sizeof(t_philo));
	philo.info = &info;
	philo.shared = &shared;
	if (run_simulation(&philo))
	{
		destroy_semaphore(&shared);
		return (exit_with(RUNTIME_FAIL));
	}
	destroy_semaphore(&shared);
	return (exit_with(SUCCESS));
}
