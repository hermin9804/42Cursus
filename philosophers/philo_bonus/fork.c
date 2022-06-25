/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:44 by mher              #+#    #+#             */
/*   Updated: 2022/06/25 21:06:39 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, t_info *info, t_shared *shared)
{
	sem_wait(shared->forks_lock);
	sem_wait(shared->forks);
	sem_wait(shared->forks);
	print_log(philo, info, FORK);
	sem_post(shared->forks_lock);
}

void	release_forks(t_shared *shared)
{
	sem_post(shared->forks);
	sem_post(shared->forks);
}
