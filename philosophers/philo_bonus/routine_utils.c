/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:44 by mher              #+#    #+#             */
/*   Updated: 2022/07/10 23:44:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	acquire_forks(t_philo *philo)
{
	if (philo->info->nop != 1)
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
