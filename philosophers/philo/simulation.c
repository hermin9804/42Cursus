/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:29 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 01:05:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	abort_simulation(t_philo *philo, t_info info)
{
	(void)philo;
	(void)info;
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
			return (abort_simulation(philo, info));
		++i;
	}
	if (pthread_create(&monitor, NULL, monitor_dead, philo))
		return (abort_simulation(philo, info));
	return (0);
}
