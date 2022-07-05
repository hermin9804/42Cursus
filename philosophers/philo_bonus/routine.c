/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/07/05 22:41:10 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	one_philo_routine(t_philo *philo)
{
	sem_wait(philo->shared->forks);
	print_log(philo, FORK);
	sem_wait(philo->shared->forks);
}

static void	eating(t_philo *philo)
{
	acquire_forks(philo);
	//sem_wait(philo->event_lock);
	pthread_mutex_lock(&philo->event_lock);
	philo->last_eat_time = get_current_time_ms();
	//sem_post(philo->event_lock);
	pthread_mutex_unlock(&philo->event_lock);
	print_log(philo, EAT);
	atomic_sleep(philo->info->tte);
	//sem_wait(philo->event_lock);
	pthread_mutex_lock(&philo->event_lock);
	if (philo->eat_count++ == philo->info->nome)
		sem_post(philo->shared->full_philos);
	//sem_post(philo->event_lock);
	pthread_mutex_unlock(&philo->event_lock);
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

void	*philo_action_routine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->info->nop == 1)
		one_philo_routine(philo);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

int	do_routine(t_philo *philo)
{
	//char		sem_name[21];
	pthread_t	philo_action;
	pthread_t	dead_observer;
	//sem_t		*event_lock;

	//set_sem_name(sem_name, philo->id);
	//if (open_semaphore(sem_name, 1, &event_lock))
	//	return (1);
	//philo->event_lock = event_lock;
	pthread_mutex_init(&(philo->event_lock), NULL);
	if (pthread_create(&philo_action, NULL, philo_action_routine, philo))
		return (1);
	if (pthread_create(&dead_observer, NULL, observe_dead, philo))
		return (1);
	return (0);
}
