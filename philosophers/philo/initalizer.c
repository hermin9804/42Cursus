/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/18 18:34:57 by mher             ###   ########.fr       */
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

//int	init_vars(t_vars *vars, t_info info)
//{
//	return (0);
//}
