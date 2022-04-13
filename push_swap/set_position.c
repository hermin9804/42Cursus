/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:56:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/14 04:06:47 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_position(t_info *info, t_rotate rotate)
{
	while (rotate.a.r && rotate.b.r)
	{
		rr(info);
		rotate.a.r--;
		rotate.b.r--;
	}
	while (rotate.a.r--)
		ra(info);
	while (rotate.b.r--)
		rb(info);
	while (rotate.a.rr && rotate.b.rr)
	{
		rrr(info);
		rotate.a.rr--;
		rotate.b.rr--;
	}
	while (rotate.a.rr--)
		rra(info);
	while (rotate.b.rr--)
		rrb(info);
	pa(info);
}

void	pb_by_pivot(t_info *info, int pivot)
{
	int	i;
	int	tmp;

	i = info->a.size;
	while (i--)
	{
		tmp = info->a.head->data;
		if (tmp > pivot)
			ra(info);
		else
			pb(info);
	}
}

void	pb_leave_three(t_info *info)
{
	int	tmp;

	while (info->a.size > 3)
	{
		tmp = info->a.head->data;
		if (tmp == info->max)
			ra(info);
		else
			pb(info);
	}
}
