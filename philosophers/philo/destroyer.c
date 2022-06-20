/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:42:28 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 13:58:27 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philos)
{
	unsigned int i;

	pthread_mutex_destroy(&(philos->shared->is_end_lock));
	i = 0;
	while (i < philos->info->nop)
	{
		pthread_mutex_destroy(&(philos[i].fork));
		pthread_mutex_destroy(&(philos[i].event_lock));
		++i;
	}
}
