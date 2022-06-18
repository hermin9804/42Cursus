/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:41:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/19 01:29:48 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_philo(t_philo *philo, t_info *info)
{
	philo = (t_philo *)malloc(sizeof(t_philo) * info->nop);
	if (philo == NULL)
		return (1);
	return (0);
}
