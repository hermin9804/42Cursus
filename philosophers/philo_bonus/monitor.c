/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:03:55 by mher              #+#    #+#             */
/*   Updated: 2022/06/25 01:40:02 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	broadcast_somone_dead(t_philo *philo)
{
	print_log(philo, DEAD);
	stop_simulation(philo);
}

static void	broadcast_everyone_full(t_philo *philos)
{
	stop_simulation(philos);
}

static int	check_philos_state(t_philo *philos)
{
	unsigned int	i;
	int				somone_dead;
	unsigned int	everyone_full;

	somone_dead = 0;
	everyone_full = (0 < philos->info->nome);
	i = 0;
	while (i < philos->info->nop)
	{
		pthread_mutex_lock(&(philos[i].event_lock));
		everyone_full &= (philos->info->nome <= philos[i].eat_count);
		if (philos->info->ttd <= get_passed_time_ms(philos[i].last_eat_time))
			somone_dead = 1;
		pthread_mutex_unlock(&(philos[i].event_lock));
		if (somone_dead)
			break ;
		++i;
	}
	if (somone_dead)
		(broadcast_somone_dead(&philos[i]));
	else if (everyone_full)
		(broadcast_everyone_full(philos));
	return (somone_dead || everyone_full);
}

void	*monitor_philos(void *_philos)
{
	t_philo			*philos;

	philos = _philos;
	while (1)
	{
		if (check_philos_state(philos))
			return (NULL);
		usleep(TIME_FOR_CONTEXT_SWITCHING);
	}
}
