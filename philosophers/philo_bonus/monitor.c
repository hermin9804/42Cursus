/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/26 16:04:04 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*broadcast_somone_dead(t_philo *philo)
{
	print_log(philo, DEAD);
	sem_wait(philo->shared->is_end_lock);
	exit(0);
	return (NULL);
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
			return (broadcast_somone_dead(philo));
		usleep(TIME_FOR_CONTEXT_SWITCHING);
	}
}
