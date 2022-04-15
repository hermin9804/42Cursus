/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:52:59 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 02:06:58 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_ascending(t_info *info)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = info->a.head;
	while (i < info->total_size)
	{
		if (cur->data == info->min)
			break ;
		cur = cur->next;
		++i;
	}
	if (i < info->a.size / 2)
	{
		while (info->a.head->data != info->min)
			ra(info);
	}
	else
	{
		while (info->a.head->data != info->min)
			rra(info);
	}
}

static void	sort_three(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a.head->data;
	mid = info->a.head->next->data;
	bot = info->a.head->prev->data;
	if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(info);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(info);
		ra(info);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(info);
	else if (mid > top && mid > bot && top > bot)
		rra(info);
}

static void	sort_stack(t_info *info)
{
	t_rotate	rotate;

	sort_three(info);
	while (info->b.size)
	{
		rotate = get_min_rotate_cnt(info);
		set_rotate_position(info, rotate);
	}
	sort_ascending(info);
}

void	push_swap(t_info *info)
{
	if (info->total_size == 2)
		sort_ascending(info);
	else if (info->total_size == 3)
		sort_three(info);
	else if (info->total_size <= 5)
	{
		pb_leave_three(info);
		sort_stack(info);
	}
	else
	{
		pb_smaller_than_pivot(info, info->f_pivot);
		pb_smaller_than_pivot(info, info->s_pivot);
		pb_leave_three(info);
		sort_stack(info);
	}
}
