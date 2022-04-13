/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:02:44 by mher              #+#    #+#             */
/*   Updated: 2022/04/14 02:53:00 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_ascending(t_info *info, int *nums)
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
		exit(0);
}
