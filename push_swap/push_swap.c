/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:52:59 by mher              #+#    #+#             */
/*   Updated: 2022/04/11 02:58:43 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_abs(long long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	push_swap(t_info *info)
{
	int	min_operation_num;
	int	i;

	while (info->a.size > 2)
	{
		pb(&info->b, &info->a);
	}
	while (info->b.size)
	{
		min_operation_num = get_min_operation_num(info);
		set_position(info, min_operation_num);
	}
	set_ascending(info);
}

void	set_position(t_info *info, int min_operation_num)
{
	int	proximate_num;

	proximate_num = get_proximate_num(&info->a, min_operation_num);
	while (info->a.head->data != proximate_num && info->b.head->data != min_operation_num)
	{
		rr(&info->a, &info->b);
	}
	while (info->a.head->data != proximate_num)
	{
		ra(&info->a);
	}
	while (info->b.head->data != min_operation_num)
	{
		rb(&info->b);
	}
	if (info->b.head->data > info->a.head->data)
		ra(&info->a);
	pa(&info->a, &info->b);
}

void	set_ascending(t_info *info)
{
	while (info->a.head->prev->data != info->max)
		ra(&info->a);
}

int	get_min_operation_num(t_info *info)
{
	int	a_r_cnt;
	int	b_r_cnt;
	int	min_cnt;
	int	min_operation_num;
	t_list	*cul;

	b_r_cnt = 0;
	min_cnt = info->total_size;
	cul = info->b.head;
	while (b_r_cnt < info->b.size)
	{
		a_r_cnt = get_rotate_cnt(&info->a, get_proximate_num(&info->a, cul->data));
		if (a_r_cnt + b_r_cnt < min_cnt)
		{
			min_cnt = a_r_cnt + b_r_cnt;
			min_operation_num = cul->data;
		}
		cul = cul->next;
		++b_r_cnt;
	}
	return (min_operation_num);
}
	
int	get_proximate_num(t_stack *stack, int data)
{
	int	i;
	int	proximate_num;
	size_t	proximate;
	size_t	tmp;
	t_list	*cul;

	i = 0;
	proximate_num = 0;
	proximate = INT_MAX - (long)INT_MIN;
	cul = stack->head;
	while (i < stack->size)
	{
		tmp = ft_abs(cul->data - data);
		if (tmp < proximate)	
		{
			proximate = tmp;
			proximate_num = cul->data;
		}
		cul = cul->next;
		++i;
	}
	return (proximate_num);
}

int	get_rotate_cnt(t_stack *stack, int proximate_num)
{
	int	cnt;
	t_list	*cul;

	cnt = 0;
	cul = stack->head;
	while (cnt < stack->size)
	{
		if (cul->data == proximate_num)
			break ;
		cul = cul->next;
		++cnt;
	}
	return (cnt);
}
