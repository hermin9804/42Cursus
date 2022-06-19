/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 00:19:56 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, t_info info, t_shared *shared)
{
	unsigned int	i;

	shared->is_end = 0;
	i = 0;
	while (i < info.nop)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].already_full = 0;
		philo[i].lfork = &(philo[i].fork);
		philo[i].rfork = &(philo[(i + 1) % info.nop].fork);
		philo[i].info = info;
		philo[i].shared = shared;
		++i;
	}
}

int	init_mutex(t_philo *philo, t_info info)
{
	unsigned int	i;

	i = 0;
	while (i < info.nop)
	{
		if (pthread_mutex_init(&(philo[i].fork), NULL))
		{
			while (i--)
				pthread_mutex_destroy(&(philo[i].fork));
			return (1);
		}
		++i;
	}
	return (0);
}
