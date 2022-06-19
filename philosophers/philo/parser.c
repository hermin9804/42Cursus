/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 00:19:23 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc, char *argv[])
{
	unsigned int	i;
	unsigned int	j;
	long long		tmp;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		tmp = 0;
		while ('0' <= argv[i][j] && argv[i][j] <= '9')
		{
			tmp = tmp * 10 + (argv[i][j] - '0');
			if (tmp > INT_MAX)
				return (1);
			++j;
		}
		if (argv[i][j] != '\0' || tmp == 0)
			return (1);
		++i;
	}
	return (0);
}

int	parse_args(t_info *info, int argc, char *argv[])
{
	if (check_args(argc, argv))
			return (1);
	info->nop = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->tte = ft_atoi(argv[3]);
	info->tts = ft_atoi(argv[4]);
	if (argc == 6)
		info->nome = ft_atoi(argv[5]);
	return (0);
}
