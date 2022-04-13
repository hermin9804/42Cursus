/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:56:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 21:50:09 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_position(t_info *info, t_rotate rotate)
{
	while (rotate.a.r && rotate.b.r)
	{
		rr(&info->a, &info->b);
		rotate.a.r--;
		rotate.b.r--;
	}
	while (rotate.a.r--)
		ra(&info->a);
	while (rotate.b.r--)
		rb(&info->b);
	while (rotate.a.rr && rotate.b.rr)
	{
		rrr(&info->a, &info->b);
		rotate.a.rr--;
		rotate.b.rr--;
	}
	while (rotate.a.rr--)
		rra(&info->a);
	while (rotate.b.rr--)
		rrb(&info->b);
	pa(&info->a, &info->b);
}

void	pb_three_divisions(t_info *info)
{
	int	tmp;

	pb_by_pivot(info, info->f_pivot);
	pb_by_pivot(info, info->s_pivot);
	while (info->a.size > 2)
	{
		tmp = info->a.head->data;
		if (tmp == info->max || tmp == info->min)
			ra(&info->a);
		else
			pb(&info->b, &info->a);
	}
}

void	pb_by_pivot(t_info *info, int pivot)
{
	int	i;
	int	tmp;

	i = info->a.size;
	while (i--)
	{
		tmp = info->a.head->data;
		if (tmp == info->max || tmp == info->min || tmp > pivot)
			ra(&info->a);
		else
			pb(&info->b, &info->a);
	}
}
