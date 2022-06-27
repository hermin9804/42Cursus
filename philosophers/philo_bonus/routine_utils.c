/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:44 by mher              #+#    #+#             */
/*   Updated: 2022/06/27 15:33:13 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->shared->forks_lock);
	sem_wait(philo->shared->forks);
	print_log(philo, FORK);
	sem_wait(philo->shared->forks);
	print_log(philo, FORK);
}

void	release_forks(t_philo *philo)
{
	sem_post(philo->shared->forks);
	sem_post(philo->shared->forks);
	sem_post(philo->shared->forks_lock);
}

void	set_sem_name(char *sem_name, unsigned int id)
{
	const char		*suffix = "event_lock";
	unsigned int	tmp;
	int	i;
	int	len;

	len = 0;
	tmp = id;
	while (tmp != 0)
	{
		tmp /= 10;
		++len;
	}
	i = len;
	while (i)
	{
		sem_name[--i] = (id % 10) + '0';
		id /= 10;
	}
	i = 0;
	while (suffix[i])
	{
		sem_name[len + i] = suffix[i];
		++i;
	}
	sem_name[len + i] = '\0';
}
