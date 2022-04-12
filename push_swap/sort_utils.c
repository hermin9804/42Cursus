/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:56:31 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 01:20:18 by mher             ###   ########.fr       */
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

t_op	get_rotate_op(t_stack *stack, int proximate_num)
{
	t_op	a;
	t_list	*cur;
	int	i;

	ft_bzero(&a, sizeof(t_op));
	cur = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (cur->data == proximate_num)
			break ;
		cur = cur->next;
		++a.r;
	}
	cur = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (cur->data == proximate_num)
			break;
		cur = cur->prev;
		++a.rr;
	}
	if (a.r < a.rr)
		a.rr = 0;
	else
		a.r = 0;
	return (a);
}

t_rotate	get_min_op(t_info *info)
{
	t_op	a;
	t_op	b;
	t_op	min_a;
	t_op	min_b;
	t_list	*cur;
	t_rotate	rotate;
	int	i;

	ft_bzero(&b, sizeof(t_op));
	min_a.r = info->a.size;
	min_a.rr = info->a.size;
	min_b.r = info->b.size;
	min_b.rr = info->b.size;
	cur = info->b.head;
	i = 0;
	while (i < info->b.size / 2)
	{
		a = get_rotate_op(&info->a, get_biggest_num(info, cur->data));
		cur = cur->next;
		if (a.r + a.rr + b.r + b.rr < min_a.r + min_a.rr + min_b.r + min_b.rr)
		{
			min_a = a;
			min_b = b;
		}
		++b.r;
		++i;
	}
	ft_bzero(&b, sizeof(t_op));
	cur = info->b.head;
	while (i < info->b.size)
	{
		a = get_rotate_op(&info->a, get_biggest_num(info, cur->data));
		cur = cur->prev;
		if (a.r + a.rr + b.r + b.rr < min_a.r + min_a.rr + min_b.r + min_b.rr)
		{
			min_a = a;
			min_b = b;
		}
		++b.rr;
		++i;
	}
	rotate.a = min_a;
	rotate.b = min_b;
	return (rotate);
}

int	get_biggest_num(t_info *info, int data)
{
	int	i;
	int	biggest_num;
	size_t	tmp;
	t_list	*cur;

	i = 0;
	biggest_num = info->max;
	cur = info->a.head;
	while (i < info->a.size)
	{
		if (data < cur->data && cur->data < biggest_num)
			biggest_num = cur->data;
		cur = cur->next;
		++i;
	}
	return (biggest_num);
}

void	pb_three_divisions(t_info *info)
{
	int	i;
	int	tmp;

	i = info->a.size;
	while (i--)
	{
		tmp = info->a.head->data;
		if (tmp == info->max || tmp == info->min || tmp > info->f_pivot)
			ra(&info->a);
		else
			pb(&info->b, &info->a);
	}
	i = info->a.size;
	while (i--)
	{
		tmp = info->a.head->data;
		if (tmp == info->max || tmp == info->min || tmp > info->s_pivot)
			ra(&info->a);
		else
			pb(&info->b, &info->a);
	}
	while (info->a.size > 2)
	{
		tmp = info->a.head->data;
		if (tmp == info->max || tmp == info->min)
			ra(&info->a);
		else
			pb(&info->b, &info->a);
	}
}

