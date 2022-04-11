/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:52:59 by mher              #+#    #+#             */
/*   Updated: 2022/04/11 18:10:53 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_abs(long long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	first_setting(t_info *info)
{
	while (info->a.size > 2)
	{
		if (info->a.head->data == info->anchor[0].data ||
				info->a.head->data == info->anchor[info->total_size - 1].data)
		{
			ra(&info->a);
		}
		else
		{
			pb(&info->b, &info->a);
		}
	}
}

void	greedy_sort(t_info *info)
{
	t_op	op;

	set_ascending(info);
	while (info->b.size)
	{
		while (info->a.head->prev->index - info->a.head->index > 1)
		{
			op = get_min_operation_cnt(info);
			set_position(info, op);
		}
		ra(&info->a);
	}
}

void	set_position(t_info *info, t_op op)
{
	while (op.r)
	{
		rb(&info->b);
		--op.r;
	}
	while (op.rr)
	{
		rrb(&info->b);
		--op.rr;
	}
	pa(&info->a, &info->b);
}

t_op	get_min_operation_cnt(t_info *info)
{
	t_op	op;
	t_list	*cul;

	ft_bzero(&op, sizeof(t_op));
	cul = info->b.head;
	while (op.r < info->b.size / 2)
	{
		if (info->a.head->index < cul->index)
			return (op);
		++op.r;
		cul = cul->next;
	}
	ft_bzero(&op, sizeof(t_op));
	cul = info->b.head;
	while (op.rr < info->b.size)
	{
		if (info->a.head->index < cul->index)
			return (op);
		++op.rr;
		cul = cul->prev;
	}
	return (op);
}

void	set_ascending(t_info *info)
{
	while (info->a.head->prev->data != info->anchor[info->total_size - 1].data)
		ra(&info->a);
}

void	push_swap(t_info *info)
{
	t_op	op;
	int	i;

	first_setting(info);
	greedy_sort(info);
	set_ascending(info);
}

//void	set_position(t_info *info, int min_operation_num)
//{
//	int	proximate_num;
//
//	proximate_num = get_proximate_num(&info->a, min_operation_num);
//	while (info->a.head->data != proximate_num && info->b.head->data != min_operation_num)
//	{
//		rr(&info->a, &info->b);
//	}
//	while (info->a.head->data != proximate_num)
//	{
//		ra(&info->a);
//	}
//	while (info->b.head->data != min_operation_num)
//	{
//		rb(&info->b);
//	}
//	if (info->b.head->data > info->a.head->data)
//		ra(&info->a);
//	pa(&info->a, &info->b);
//}
	
//int	get_proximate_num(t_stack *stack, int data)
//{
//	int	i;
//	int	proximate_num;
//	size_t	proximate;
//	size_t	tmp;
//	t_list	*cul;
//
//	i = 0;
//	proximate_num = 0;
//	proximate = INT_MAX - (long)INT_MIN;
//	cul = stack->head;
//	while (i < stack->size)
//	{
//		tmp = ft_abs(cul->data - data);
//		if (tmp < proximate)	
//		{
//			proximate = tmp;
//			proximate_num = cul->data;
//		}
//		cul = cul->next;
//		++i;
//	}
//	return (proximate_num);
//}
//
//int	get_rotate_cnt(t_stack *stack, int proximate_num)
//{
//	int	cnt;
//	t_list	*cul;
//
//	cnt = 0;
//	cul = stack->head;
//	while (cnt < stack->size)
//	{
//		if (cul->data == proximate_num)
//			break ;
//		cul = cul->next;
//		++cnt;
//	}
//	return (cnt);
//}

//t_op	get_min_op(t_info *info)
//{
//	t_op	op;
//	t_op	tmp;
//	int	min_cnt;
//	int	min_operation_num;
//	t_list	*cul;
//
//	min_cnt = info->total_size;
//	cul = info->b.head;
//	while (b_r_cnt < info->b.size)
//	{
//		ft_bzero(&tmp, sizeof(t_op));
//		tmp = get_rotate_cnt(&info->a, get_proximate_num(&info->a, cul->data));
//		if (a_r_cnt + b_r_cnt < min_cnt)
//		{
//			min_cnt = a_r_cnt + b_r_cnt;
//			min_operation_num = cul->data;
//		}
//		cul = cul->next;
//		++b_r_cnt;
//	}
//	return (min_operation_num);
//}

//t_op	get_op_cnt(t_stack *stack, int proximate_num)
//{
//	int	cnt;
//	t_list	*cul;
//
//	cnt = 0;
//	cul = stack->head;
//	while (cnt < stack->size)
//	{
//		if (cul->data == proximate_num)
//			break ;
//		cul = cul->next;
//		++cnt;
//	}
//	return (cnt);
//}

