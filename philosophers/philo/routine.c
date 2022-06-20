/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 14:50:54 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	printf("%d has taken a fork\n", philo->id);
	pthread_mutex_lock(philo->rfork);
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
	usleep(philo->info->tte * 1000);
	printf("%d is eating\n", philo->id);
	pthread_mutex_unlock(&(philo->event_lock));
	release_forks(philo);
	return (0);
}

static int sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->event_lock));
	printf("%d is sleeping\n", philo->id);
	usleep(philo->info->tts * 1000);
	pthread_mutex_unlock(&(philo->event_lock));
	return (0);
}

static int thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
	return (0);
}

void	*do_routine(void *philo)
{
	t_philo	*p;
	
	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(p))
			return (NULL);
		if (sleeping(p))
			return (NULL);
		if (thinking(p))
			return (NULL);
	}
	return (NULL);
}
