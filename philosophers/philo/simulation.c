/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:29 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 02:40:28 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_all_thread(pthread_t *monitor, t_philo *philos, unsigned int i)
{
	if (monitor != NULL)
		pthread_join(*monitor, NULL);
	while (i--)
		pthread_join(philos[i].thread, NULL);
}

// TODO
static int	abort_simulation(t_philo *philos, t_info info, unsigned int i)
{
	(void)philos;
	(void)info;
	(void)i;
	return (1);
}

int	run_simulation(t_philo *philos, t_info info, t_shared *shared)
{
	unsigned int	i;
	time_t			now;
	pthread_t		monitor;

	shared->start_time = get_time_ms();
	i = 0;
	while (i < info.nop)
	{
		now	= get_time_ms();
		philos[i].start_eat_time = now;
		philos[i].last_eat_time = now;
		if (pthread_create(&(philos[i].thread), NULL, do_routine, &philos[i]))
			return (abort_simulation(philos, info, i));
		++i;
	}
	if (pthread_create(&monitor, NULL, monitor_dead, philos))
		return (abort_simulation(philos, info, i));
	join_all_thread(&monitor, philos, i);
	return (0);
}
