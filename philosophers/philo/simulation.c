/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:29 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 02:03:08 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_all_thread(pthread_t *monitor, t_philo *philo, unsigned int i)
{
	if (monitor != NULL)
		pthread_join(*monitor, NULL);
	while (i--)
		pthread_join(philo[i].thread, NULL);
}

static int	abort_simulation(t_philo *philo, t_info info, unsigned int i)
{
	(void)philo;
	(void)info;
	(void)i;
	return (1);
}

int	run_simulation(t_philo *philo, t_info info, t_shared *shared)
{
	unsigned int	i;
	time_t			now;
	pthread_t		monitor;

	shared->start_time = get_time_ms();
	i = 0;
	while (i < info.nop)
	{
		now	= get_time_ms();
		philo[i].start_eat_time = now;
		philo[i].last_eat_time = now;
		if (pthread_create(&(philo[i].thread), NULL, do_routine, &philo[i]))
			return (abort_simulation(philo, info, i));
		++i;
	}
	if (pthread_create(&monitor, NULL, monitor_dead, philo))
		return (abort_simulation(philo, info, i));
	join_all_thread(&monitor, philo, i);
	return (0);
}
