/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/28 17:43:11 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_full_routine(void *_arg)
{
	unsigned int	i;
	t_monitor_arg	*monitor_arg;

	monitor_arg = (t_monitor_arg *)_arg;
	i = 0;
	while (i < monitor_arg->info->nop)
	{
		sem_wait(monitor_arg->shared->full_philos);
		++i;
	}
	sem_wait(monitor_arg->shared->end_lock);
	kill(monitor_arg->pids[--i], SIGTERM);
	return (NULL);
}

int	monitor_full_philos(pthread_t *full_monitor, t_philo *philo, pid_t *pids)
{
	t_monitor_arg	monitor_arg;

	if (philo->info->nome == 0)
		return (0);
	monitor_arg.info = philo->info;
	monitor_arg.shared = philo->shared;
	monitor_arg.pids = pids;
	if (pthread_create(full_monitor, NULL, monitor_full_routine, &monitor_arg))
		return (1);
	pthread_detach(*full_monitor);
	return (0);
}

static void	*broadcast_somone_dead(t_philo *philo)
{
	time_t	time_stamp;

	time_stamp = get_passed_time_ms(philo->info->start_at);
	sem_wait(philo->shared->end_lock);
	printf(C_PRPL "%ld %u died\n" C_RESET, time_stamp, philo->id);
	exit(0);
	return (NULL);
}

void	*monitor_dead_routine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	while (1)
	{
		sem_wait(philo->event_lock);
		if (philo->info->ttd <= get_passed_time_ms(philo->last_eat_time))
			return (broadcast_somone_dead(philo));
		sem_post(philo->event_lock);
		usleep(TIME_FOR_CONTEXT_SWITCHING);
	}
}
