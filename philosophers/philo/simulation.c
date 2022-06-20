/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:29 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 20:57:51 by mher             ###   ########.fr       */
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

// TODO: 만들어야함 
static int	abort_simulation(t_philo *philos, t_info *info, unsigned int i)
{
	(void)philos;
	(void)info;
	(void)i;
	return (1);
}

int	is_end_simulation(t_philo *philo)
{
	int	is_end;

	pthread_mutex_lock(&philo->shared->is_end_lock);
	is_end = philo->shared->is_end;
	pthread_mutex_unlock(&philo->shared->is_end_lock);
	return (is_end);
}

int	run_simulation(t_philo *philos, t_info *info)
{
	unsigned int	i;
	time_t			now;
	pthread_t		monitor;

	now	= get_time_ms();
	i = 0;
	while (i < info->nop)
	{
		philos[i].start_eat_time = now;
		philos[i].last_eat_time = now;
		if (pthread_create(&(philos[i].thread), NULL, do_routine, &philos[i]))
			return (abort_simulation(philos, info, i));
		++i;
	}
	if (pthread_create(&monitor, NULL, monitor_philos, philos))
		return (abort_simulation(philos, info, i));
	join_all_thread(&monitor, philos, i);
	return (0);
}
