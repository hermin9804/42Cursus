/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/06/25 22:43:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//static	void	*one_philo_routine(t_philo *philo)
//{
//	pthread_mutex_lock(philo->lfork);
//	print_log(philo, FORK);
//	while (!is_end_simulation(philo))
//		usleep(TIME_FOR_CONTEXT_SWITCHING);
//	pthread_mutex_unlock(philo->lfork);
//	return (NULL);
//}

static	void eating(t_philo *philo)
{
	take_forks(philo);
	philo->last_eat_time = get_current_time_ms();
	print_log(philo, EAT);
	philo->eat_count++;
	snooze(philo->info->tte);
	release_forks(philo->shared);
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
	char	sem_name[30];

	init_sem_name(sem_name, philo->id);
	if (sem_open(sem_name, 1, philo->event_lock))
		return (1);
	while (1)
	{
		eating(philo); 
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
