/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/29 20:34:15 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_full(t_philo *philo)
{
	pid_t			monitor_pid;
	unsigned int	i;

	if (philo->info->nome == 0)
		return (0);
	monitor_pid = fork();
	if (monitor_pid == -1)
		return (1);
	else if (monitor_pid == 0)
	{
		i = philo->info->nop;
		while (--i)
			sem_wait(philo->shared->full_philos);
		exit(0);
	}
	return (0);
}

static void	broadcast_somone_dead(t_philo *philo)
{
	time_t	time_stamp;

	sem_wait(philo->shared->end_lock);
	time_stamp = get_passed_time_ms(philo->info->start_at);
	printf(C_PRPL "%ld %u died\n" C_RESET, time_stamp, philo->id);
}

void	*monitor_dead(void *_philo)
{
	t_philo	*philo;
	int		is_dead;

	philo = (t_philo *)_philo;
	while (1)
	{
		sem_wait(philo->event_lock);
		is_dead = philo->info->ttd <= get_passed_time_ms(philo->last_eat_time);
		sem_post(philo->event_lock);
		if (is_dead)
		{
			broadcast_somone_dead(philo);
			exit(0);
		}
		usleep(TIME_FOR_CONTEXT_SWITCHING);
	}
}
