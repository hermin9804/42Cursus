/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:44 by mher              #+#    #+#             */
/*   Updated: 2022/07/11 00:20:24 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	acquire_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_log(philo, FORK);
	pthread_mutex_lock(philo->rfork);
	print_log(philo, FORK);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
}
