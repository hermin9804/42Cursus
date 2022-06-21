/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/06/21 14:53:59 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
	printf("%d has taken a fork\n", philo->id);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}

static	int eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&(philo->event_lock));
	philo->last_eat_time = get_time_ms();
	usleep(philo->info->tte * 1000);
	printf("%d is eating\n", philo->id);
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->event_lock));
	release_forks(philo);
	return (is_end_simulation(philo));
}

static int sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	usleep(philo->info->tts * 1000);
	return (is_end_simulation(philo));
}

static int thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
	return (is_end_simulation(philo));
}

void	*do_routine(void *_philo)
{
	t_philo	*philo;
	
	philo = (t_philo *)_philo;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
	return (NULL);
}
