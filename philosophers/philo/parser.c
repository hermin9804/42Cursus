/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/25 17:52:18 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str++ - '0');
		if (ret < 0)
			return ((sign + 1) / -2);
	}
	return (sign * ret);
}

static int	check_args(int argc, char *argv[])
{
	int	i;
	int	j;
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
	memset(info, 0, sizeof(t_info));
	info->nop = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->tte = ft_atoi(argv[3]);
	info->tts = ft_atoi(argv[4]);
	if (argc == 6)
		info->nome = ft_atoi(argv[5]);
	return (0);
}
