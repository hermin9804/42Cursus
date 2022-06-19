/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 02:38:40 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philos, t_info info, t_shared *shared)
{
	unsigned int	i;

	shared->is_end = 0;
	i = 0;
	while (i < info.nop)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].already_full = 0;
		philos[i].lfork = &(philos[i].fork);
		philos[i].rfork = &(philos[(i + 1) % info.nop].fork);
		philos[i].info = info;
		philos[i].shared = shared;
		++i;
	}
}

static int	init_mutex_fork_event(t_philo *philo)
{
	if (pthread_mutex_init(&(philo->fork), NULL))
		return (1);
	if (pthread_mutex_init(&(philo->event_lock), NULL))
	{
		pthread_mutex_destroy(&(philo->fork));
		return (1);
	}
	return (0);
}

int	init_mutex(t_philo *philos, t_info info, t_shared *shared)
{
	unsigned int	i;

	if (pthread_mutex_init(&(shared->is_end_lock), NULL))
		return (1);
	i = 0;
	while (i < info.nop)
	{
		if (init_mutex_fork_event(&(philos[i])))
		{
			while (i--)
			{
				pthread_mutex_destroy(&(philos[i].fork));
				pthread_mutex_destroy(&(philos[i].event_lock));
			}
			pthread_mutex_destroy(&(shared->is_end_lock));
			return (1);
		}
		++i;
	}
	return (0);
}
