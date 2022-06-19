/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/19 15:20:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *philo, t_info *info)
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
	return (0);
}

int	init_mutex(t_philo *philo, t_info *info)
{
	return (0);
}
