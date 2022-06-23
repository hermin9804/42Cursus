/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/06/21 18:58:15 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int eating(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&(philo->event_lock));
	philo->last_eat_time = get_time_ms();
	busy_wait(get_time_ms(), philo->info->tte);
	print_log(philo, EAT);
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->event_lock));
	release_forks(philo);
	return (is_end_simulation(philo));
}

static int sleeping(t_philo *philo)
{
	print_log(philo, SLEEP);
	busy_wait(get_time_ms(), philo->info->tts);
	return (is_end_simulation(philo));
}

static int thinking(t_philo *philo)
{
	print_log(philo, THINK);
	usleep(FOR_OTHER_PHILOS);
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