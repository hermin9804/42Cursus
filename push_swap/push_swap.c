/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:52:59 by mher              #+#    #+#             */
/*   Updated: 2022/04/12 01:01:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_ascending(t_info *info)
{
	while (info->a.head->prev->data != info->max)
		rra(&info->a);
}

size_t	ft_abs(long long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	sort_three(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a.head->data;
	mid = info->a.head->next->data;
	bot = info->a.head->prev->data;
	if (top > mid && mid > bot && top > bot)
	{
		sa(&info->a);
		rra(&info->a);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(&info->a);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(&info->a);
		ra(&info->a);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(&info->a);
	else if (mid > top && mid > bot && top > bot)
		rra(&info->a);
}

void	push_swap(t_info *info)
{
	int	min_operation_num;
	int	i;

	t_rotate	rotate;

	if (info->total_size == 2)
	{
		set_ascending(info);
		return ;
	}
	else if (info->total_size == 3)
	{
		sort_three(info);
		return ;
	}
	while (info->a.size > 2)
	{
		pb(&info->b, &info->a);
	}
	while (info->b.size)
	{
		rotate = get_min_op(info);
		set_rotate_position(info, rotate);
	}
	set_ascending(info);
}

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
	if (info->b.head->data > info->a.head->data)
		ra(&info->a);
	pa(&info->a, &info->b);
}



t_op	get_rotate_op(t_stack *stack, int proximate_num)
{
	t_op	a;
	t_list	*cul;
	int	i;

	ft_bzero(&a, sizeof(t_op));
	cul = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (cul->data == proximate_num)
			break ;
		cul = cul->next;
		++a.r;
	}
	cul = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (cul->data == proximate_num)
			break;
		cul = cul->prev;
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
	t_list	*cul;
	t_rotate	rotate;
	int	i;

	ft_bzero(&b, sizeof(t_op));
	min_a.r = info->a.size;
	min_a.rr = info->a.size;
	min_b.r = info->b.size;
	min_b.rr = info->b.size;
	cul = info->b.head;
	i = 0;
	while (i < info->b.size / 2)
	{
		a = get_rotate_op(&info->a, get_proximate_num(&info->a, cul->data));
		cul = cul->next;
		if (a.r + a.rr + b.r + b.rr < min_a.r + min_a.rr + min_b.r + min_b.rr)
		{
			min_a = a;
			min_b = b;
		}
		++b.r;
		++i;
	}
	ft_bzero(&b, sizeof(t_op));
	cul = info->b.head;
	while (i < info->b.size)
	{
		a = get_rotate_op(&info->a, get_proximate_num(&info->a, cul->data));
		cul = cul->prev;
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

/////////////////////

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

void	set_position(t_info *info, int min_operation_num)
{
	int	proximate_num;

	proximate_num = get_proximate_num(&info->a, min_operation_num);
	while (info->a.head->data != proximate_num && info->b.head->data != min_operation_num)
		rr(&info->a, &info->b);
	while (info->a.head->data != proximate_num)
		ra(&info->a);
	while (info->b.head->data != min_operation_num)
		rb(&info->b);
	if (info->b.head->data > info->a.head->data)
		ra(&info->a);
	pa(&info->a, &info->b);
}

int	get_mid_data(t_stack *stack)
{
	int	i;
	t_list	*cul;
	
	i = 0;
	cul = stack->head;
	while (i < stack->size / 2)
	{
		cul = cul->next;	
		++i;
	}
	return (cul->data);
}
