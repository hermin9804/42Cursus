/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_rotate_cnt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:34:47 by mher              #+#    #+#             */
/*   Updated: 2022/04/14 02:19:01 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op	get_a_rotate_cnt(t_stack *stack, int target)
{
	int		i;
	t_op	a;
	t_list	*go_next;
	t_list	*go_prev;

	go_next = stack->head;
	go_prev = stack->head;
	ft_bzero(&a, sizeof(t_op));
	i = 0;
	while (i < stack->size)
	{
		if (go_next->data == target)
			a.r = i;
		if (go_prev->data == target)
			a.rr = i;
		go_next = go_next->next;
		go_prev = go_prev->prev;
		++i;
	}
	if (a.r < a.rr)
		a.rr = 0;
	else
		a.r = 0;
	return (a);
}

static int	get_valid_bottom_num(t_info *info, int data)
{
	int		i;
	int		bottom_num;
	t_list	*cur;

	i = 0;
	bottom_num = info->max;
	cur = info->a.head;
	while (i < info->a.size)
	{
		if (data < cur->data && cur->data < bottom_num)
			bottom_num = cur->data;
		cur = cur->next;
		++i;
	}
	return (bottom_num);
}

static void	get_rotate_cnt(t_info *info, t_rotate *tmp, t_rotate *min)
{
	int		i;
	t_list	*cur;
	int		valid_bottom_num;

	cur = info->b.head;
	i = 0;
	while (i < info->b.size / 2)
	{
		valid_bottom_num = get_valid_bottom_num(info, cur->data);
		tmp->a = get_a_rotate_cnt(&info->a, valid_bottom_num);
		if (tmp->a.r + tmp->a.rr + tmp->b.r < min->a.r + min->a.rr + min->b.r)
		{
			min->a = tmp->a;
			min->b = tmp->b;
		}
		cur = cur->next;
		++tmp->b.r;
		++i;
	}
}

static void	get_r_rotate_cnt(t_info *info, t_rotate *tmp, t_rotate *min)
{
	int		i;
	t_list	*cur;
	int		valid_bottom_num;

	ft_bzero(&tmp->b, sizeof(t_op));
	cur = info->b.head;
	i = info->b.size / 2;
	while (i < info->b.size)
	{
		valid_bottom_num = get_valid_bottom_num(info, cur->data);
		tmp->a = get_a_rotate_cnt(&info->a, valid_bottom_num);
		cur = cur->prev;
		if (tmp->a.r + tmp->a.rr + tmp->b.rr < min->a.r + min->a.rr + min->b.rr)
		{
			min->a = tmp->a;
			min->b = tmp->b;
		}
		++tmp->b.rr;
		++i;
	}
}

t_rotate	get_min_rotate_cnt(t_info *info)
{
	t_list		*cur;
	t_rotate	tmp;
	t_rotate	min;

	ft_bzero(&tmp, sizeof(t_rotate));
	min.a.r = info->a.size;
	min.a.rr = info->a.size;
	min.b.r = info->b.size;
	min.b.rr = info->b.size;
	cur = info->b.head;
	get_rotate_cnt(info, &tmp, &min);
	get_r_rotate_cnt(info, &tmp, &min);
	return (min);
}
