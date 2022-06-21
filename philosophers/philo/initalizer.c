/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/21 17:13:31 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_philo(t_philo **philos, t_info *info)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * info->nop);
	if (*philos == NULL)
		return (1);
	return (0);
}

void	init_philo(t_philo *philos, t_info *info, t_shared *shared)
{
	unsigned int	i;

	shared->is_end = 0;
	i = 0;
	while (i < info->nop)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].lfork = &(philos[i].fork);
		philos[i].rfork = &(philos[(i + 1) % info->nop].fork);
		philos[i].info = info;
		philos[i].shared = shared;
		++i;
	}
}
