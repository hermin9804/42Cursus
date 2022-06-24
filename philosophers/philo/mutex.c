/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:47:29 by mher              #+#    #+#             */
/*   Updated: 2022/06/24 17:28:09 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	init_mutex(t_philo *philos, t_info *info, t_end_state *end_state)
{
	unsigned int	i;

	if (pthread_mutex_init(&(end_state->is_end_lock), NULL))
		return (1);
	i = 0;
	while (i < info->nop)
	{
		if (init_mutex_fork_event(&(philos[i])))
		{
			while (i--)
			{
				pthread_mutex_destroy(&(philos[i].fork));
				pthread_mutex_destroy(&(philos[i].event_lock));
			}
			pthread_mutex_destroy(&(end_state->is_end_lock));
			return (1);
		}
		++i;
	}
	return (0);
}

void	destroy_mutex(t_philo *philos)
{
	unsigned int i;

	pthread_mutex_destroy(&(philos->end_state->is_end_lock));
	i = 0;
	while (i < philos->info->nop)
	{
		pthread_mutex_destroy(&(philos[i].fork));
		pthread_mutex_destroy(&(philos[i].event_lock));
		++i;
	}
}
