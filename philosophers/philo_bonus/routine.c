/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/06/26 16:00:27 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void eating(t_philo *philo)
{
	take_forks(philo);
	sem_wait(philo->event_lock);
	philo->last_eat_time = get_current_time_ms();
	sem_post(philo->event_lock);
	print_log(philo, EAT);
	snooze(philo->info->tte);
	sem_wait(philo->event_lock);
	philo->eat_count++;
	sem_post(philo->event_lock);
	release_forks(philo);
}

static void sleeping(t_philo *philo)
{
	print_log(philo, SLEEP);
	snooze(philo->info->tts);
}

static void thinking(t_philo *philo)
{
	print_log(philo, THINK);
	usleep(TIME_FOR_CONTEXT_SWITCHING);
}

int	do_routine(t_philo *philo)
{
	char		sem_name[21];
	pthread_t	monitor;

	set_sem_name(sem_name, philo->id);
	if (open_semaphore(sem_name, 1, &(philo->event_lock)))
		return (1);
	if (pthread_create(&monitor, NULL, monitor_dead, philo))
		return (1);
	while (1)
	{
		eating(philo); 
		sleeping(philo);
		thinking(philo);
	}
}
