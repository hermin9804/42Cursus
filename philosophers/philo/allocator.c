/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:41:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 02:37:43 by mher             ###   ########.fr       */
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
