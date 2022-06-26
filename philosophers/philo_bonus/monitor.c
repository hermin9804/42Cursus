/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/26 17:52:43 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_full(void *_philo)
{
	unsigned int	i;
	t_philo			*philo;

	philo = (t_philo *)_philo;
	i = 0;
	while (i < philo->info->nop)
	{
		sem_wait(philo->shared->full_philos);
		++i;
	}
	kill(philo->pids[--i], SIGTERM);
	return (NULL);
}

static void	*broadcast_somone_dead(t_philo *philo)
{
	time_t	time_stamp;

	time_stamp = get_passed_time_ms(philo->info->start_at);
	sem_wait(philo->shared->is_end_lock);
	printf(C_PRPL "%ld %u died\n" C_RESET, time_stamp, philo->id);
	exit(0);
	return (NULL);
}

void	*monitor_dead(void *_philo)
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
