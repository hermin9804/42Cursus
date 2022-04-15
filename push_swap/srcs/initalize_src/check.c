/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:02:44 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 19:57:44 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	check_dup(int *nums, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (nums[i] == nums[i + 1])
			error_exit();
		++i;
	}
}

int	check_ascending(t_info *info, int *nums)
{
	int	i;
	int	cnt;
	t_list	*cur;

	i = 0;
	cnt = 0;
	cur = info->a.head;
	while (i < info->total_size)
	{
		if (cur->data == nums[i])
			++cnt;
		cur = cur->next;
		++i;
	}
	if (cnt == info->total_size)
		return (1);
	return (0);
}

int	check_num_atoi(const char *str)
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
	if (*str < '0' || '9' < *str)
		error_exit();
	while ('0' <= *str && *str <= '9')
	{
		ret = (ret * 10) + ((*str - '0') * sign);
		if (ret < INT_MIN || INT_MAX < ret)
			error_exit();
		if (*str < '0' || '9' < *str)
			error_exit();
		++str;
	}
	return (ret);
}
