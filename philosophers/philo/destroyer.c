/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:42:28 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 01:54:05 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philo)
{
	unsigned int i;

	pthread_mutex_destroy(&(philo->shared->is_end_lock));
	i = 0;
	while (i < philo->info.nop)
	{
		pthread_mutex_destroy(&(philo[i].fork));
		++i;
	}
}
