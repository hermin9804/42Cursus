/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/18 19:40:21 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int argc, char *argv[])
{
	int	tmp;

	if (argc != 5 && argc != 6)
		return (1);
	if (check_valid_atoi(argv[1], &tmp))
		return (1);
	info->nop = tmp;
	if (check_valid_atoi(argv[2], &tmp))
		return (1);
	info->ttd = tmp;
	if (check_valid_atoi(argv[3], &tmp))
		return (1);
	info->tte = tmp;
	if (check_valid_atoi(argv[4], &tmp))
		return (1);
	info->tts = tmp;
	if (argc == 6)
	{
		if (check_valid_atoi(argv[5], &tmp))
			return (1);
		info->nome = tmp;
	}
	else
		info->nome = 0;
	return (0);
}

static int	init_forks(pthread_mutex_t *forks, int nop)
{
	int				i;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nop);
	if (forks == NULL)
		return (1);
	i = 0;
	while (i < nop)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			while (i--)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (1);
		}
		++i;
	}
	return (0);
}

int	init_vars(t_vars *vars, const t_info info)
{
	vars->dead_flag = 0;
	vars->full_flag = 0;
	if (init_forks(vars->forks, info.nop))
		return (1);
	return (0);
}
