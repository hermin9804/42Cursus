/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:56:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 02:54:11 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_position(t_info *info, t_rotate rotate)
{
	while (rotate.a.r && rotate.b.r)
	{
		rr(info, 'p');
		rotate.a.r--;
		rotate.b.r--;
	}
	while (rotate.a.r--)
		ra(info, 'p');
	while (rotate.b.r--)
		rb(info, 'p');
	while (rotate.a.rr && rotate.b.rr)
	{
		rrr(info, 'p');
		rotate.a.rr--;
		rotate.b.rr--;
	}
	while (rotate.a.rr--)
		rra(info, 'p');
	while (rotate.b.rr--)
		rrb(info, 'p');
	pa(info, 'p');
}

void	pb_smaller_than_pivot(t_info *info, int pivot)
{
	int	i;
	int	tmp;

	i = info->a.size;
	while (0 < i--)
	{
		tmp = info->a.head->data;
		if (tmp < pivot)
			pb(info, 'p');
		else
			ra(info, 'p');
	}
}

void	pb_leave_three(t_info *info)
{
	int	tmp;

	while (info->a.size > 3)
	{
		tmp = info->a.head->data;
		if (tmp == info->max)
			ra(info, 'p');
		else
			pb(info, 'p');
	}
}
