/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/19 15:44:26 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	init_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nop)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].already_full = 0;
		philo[i].lfork = &(philo[i].fork);
		philo[i].rfork = &(philo[(i + 1) % info->nop].fork);
		philo[i].info = info;
		++i;
	}
}

int	init_mutex(t_philo *philo, t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->key), NULL))
		return (1);
	i = 0;
	while (i < info->nop)
	{
		if (pthread_mutex_init(&(philo[i].fork), NULL))
		{
			while (i--)
				pthread_mutex_destroy(&(philo[i].fork));
			pthread_mutex_destroy(&(info->key));
			return (1);
		}
		++i;
	}
	return (0);
}
