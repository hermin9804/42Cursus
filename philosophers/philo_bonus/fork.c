/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:44 by mher              #+#    #+#             */
/*   Updated: 2022/06/25 22:40:54 by mher             ###   ########.fr       */
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

void	init_sem_name(char sem_name[30], unsigned int id)
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
	memset(sem_name, 0, 30);
	i = len;
	while (i)
	{
		sem_name[--i] = (id % 10) + '0';
		id /= 10;
	}
	i = len;
	while (suffix[i])
	{
		sem_name[i] = suffix[i];
		++i;
	}
}
