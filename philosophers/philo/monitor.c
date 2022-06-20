/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 21:25:30 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starvation(t_philo *philos)
{
	unsigned int	i;
	int				some_one_starved;

	some_one_starved = 0;
	i = 0;
	while (i < philos->info->nop)
	{
		pthread_mutex_lock(&(philos[i].event_lock));
		if (get_passed_time_ms(philos[i].last_eat_time) > philos->info->ttd)
			some_one_starved = 1;
		pthread_mutex_unlock(&(philos[i].event_lock));
		if (some_one_starved)
		{
			pthread_mutex_lock(&(philos->shared->is_end_lock));
			philos->shared->is_end = 1;
			pthread_mutex_unlock(&(philos->shared->is_end_lock));
			return (1);
		}
		++i;
	}
	return (0);
}

int	check_all_full(t_philo *philos)
{
	unsigned int	i;
	unsigned int	full_philo_cnt;

	full_philo_cnt = 0;
	i = 0;
	while (i < philos->info->nop)
	{
		pthread_mutex_lock(&(philos[i].event_lock));
		if (philos->info->nome && philos[i].eat_count >= philos->info->nome)
			++full_philo_cnt;
		pthread_mutex_unlock(&(philos[i].event_lock));
		++i;
	}
	if (philos->info->nome > 0 && full_philo_cnt >= philos->info->nop)
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
		if (check_all_full(philos))
			return (NULL);
		if (check_starvation(philos))
			return (NULL);
	}
}
