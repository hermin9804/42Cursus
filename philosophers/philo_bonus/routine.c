/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/07/10 23:23:46 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	acquire_forks(philo);
	sem_wait(philo->shared->event_lock[philo->id]);
	philo->last_eat_time = get_current_time_ms();
	sem_post(philo->shared->event_lock[philo->id]);
	print_log(philo, EAT);
	atomic_sleep(philo->info->tte);
	if (philo->eat_count++ == philo->info->nome)
		sem_post(philo->shared->full_philos);
	release_forks(philo);
}

static void	sleeping(t_philo *philo)
{
	print_log(philo, SLEEP);
	atomic_sleep(philo->info->tts);
}

static void	thinking(t_philo *philo)
{
	print_log(philo, THINK);
	usleep(TIME_FOR_CONTEXT_SWITCHING);
}

int	do_routine(t_philo *philo)
{
	pthread_t	dead_observer;

	if (pthread_create(&dead_observer, NULL, observe_dead, philo))
		return (1);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
