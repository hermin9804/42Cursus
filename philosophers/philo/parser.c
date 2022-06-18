/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/18 23:39:23 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc, char *argv[])
{
	int			i;
	int			j;
	long long	tmp;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		tmp = 0;
		while (ft_isdigit(argv[i][j]))
		{
			tmp = tmp * 10 + (argv[i][j] - '0');
			if (tmp > INT_MAX)
				return (1);
			++j;
		}
		if (argv[i][j] != '\0')
			return (1);
		++i;
	}
	return (0);
}

int	parse_args(t_info *info, int argc, char *argv[])
{
	if (check_args(argc, argv))
			return (1);
	memset(info, 0, sizeof(t_info));
	info->nop = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->tte = ft_atoi(argv[3]);
	info->tts = ft_atoi(argv[4]);
	if (argc == 6)
		info->nome = ft_atoi(argv[5]);
	return (0);
}
