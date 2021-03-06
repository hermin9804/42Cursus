/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:29 by mher              #+#    #+#             */
/*   Updated: 2022/07/05 15:58:16 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->end_state->is_end_lock);
	philo->end_state->is_end = 1;
	pthread_mutex_unlock(&philo->end_state->is_end_lock);
}

static int	join_philos(t_philo *philos, unsigned int i)
{
	while (i--)
		pthread_join(philos[i].thread, NULL);
	return (1);
}

static int	join_all(pthread_t *observer, t_philo *philos, unsigned int i)
{
	join_philos(philos, i);
	pthread_join(*observer, NULL);
	return (1);
}

int	is_end_simulation(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->end_state->is_end_lock);
	ret = philo->end_state->is_end;
	pthread_mutex_unlock(&philo->end_state->is_end_lock);
	return (ret);
}

int	run_simulation(t_philo *philos, t_info *info)
{
	unsigned int	i;
	time_t			current_time;
	pthread_t		observer;

	current_time = get_current_time_ms();
	philos->info->start_at = current_time;
	i = 0;
	while (i < info->nop)
	{
		philos[i].last_eat_time = current_time;
		if (pthread_create(&(philos[i].thread), NULL, do_routine, &philos[i]))
		{
			stop_simulation(&philos[i]);
			return (join_philos(philos, i));
		}
		++i;
	}
	if (pthread_create(&observer, NULL, observe_philos, philos))
	{
		stop_simulation(&philos[i]);
		return (join_all(&observer, philos, i));
	}
	join_all(&observer, philos, i);
	return (0);
}
