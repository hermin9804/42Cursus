/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/21 15:09:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos_state(t_philo *philos)
{
	unsigned int	i;
	unsigned int	all_philos_full;
	int				some_one_starved;

	all_philos_full = (0 < philos->info->nome);
	i = 0;
	while (i < philos->info->nop)
	{
		pthread_mutex_lock(&(philos[i].event_lock));
		all_philos_full &= (philos->info->nome <= philos[i].eat_count);
		some_one_starved = (philos->info->ttd <= get_passed_time_ms(philos[i].last_eat_time));
		pthread_mutex_unlock(&(philos[i].event_lock));
		if (some_one_starved)
			break ;
		++i;
	}
	if (some_one_starved)
	{
		pthread_mutex_lock(&(philos->shared->is_end_lock));
		philos->shared->is_end = 1;
		pthread_mutex_unlock(&(philos->shared->is_end_lock));
		return (1);
	}
	if (all_philos_full)
	{
		pthread_mutex_lock(&(philos->shared->is_end_lock));
		philos->shared->is_end = 1;
		pthread_mutex_unlock(&(philos->shared->is_end_lock));
		return (1);
	}
	return (0);
}

void	*monitor_philos(void *_philos)
{
	t_philo			*philos;

	philos = _philos;
	while (1)
	{
		if (check_philos_state(philos))
			return (NULL);
	}
}
