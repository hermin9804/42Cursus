/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:43:57 by mher              #+#    #+#             */
/*   Updated: 2022/07/10 23:44:25 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_sem_name(char *sem_name, unsigned int id)
{
	const char		*suffix = "event_lock";
	unsigned int	tmp;
	int				i;
	int				len;

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
