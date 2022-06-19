/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:13:23 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 02:11:36 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int eating(t_philo *philo)
{
	printf("%d is eating\n", philo->id);
	return (0);
}

static int sleeping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	return (0);
}

static int thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
	return (0);
}


void	*do_routine(void *philo)
{
	t_philo	*p;
	
	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(p))
			return (NULL);
		if (sleeping(p))
			return (NULL);
		if (thinking(p))
			return (NULL);
	}
	return (NULL);
}
