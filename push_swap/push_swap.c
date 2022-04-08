/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:52:59 by mher              #+#    #+#             */
/*   Updated: 2022/04/08 19:28:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->size > 2)
		pb(b, a);
	print_stack(a);
	print_stack(b);
	while (b->size)
	{
		min_index = get_min_index(a, b);
		set_position(a, b, min_index);
	}
}

int	get_proximate_index(t_stack *a, int index)
{
	int	i;	
	int	result;
	int	proximate;
	t_list	*cul;

	i = 0;
	result = 0;
	proximate = a->total_size;
	cul = a->head;
	while (i < a->size)
	{
		if (ft_abs(cul->index - index) < proximate)	
		{
			proximate = ft_abs(cul->index - index);
			result = cul->index;
		}
		cul = cul->next;
		++i;
	}
	return (result);
}

void	set_position(t_stack *a, t_stack *b, int min_index)
{
	int	target_index;

	target_index = get_proximate_index(a, min_index);
	while (a->head->index != target_index)
		ra(a);
	while (b->head->index != min_index)
		rb(b);
	pa(a, b);
}

int	get_min_index(t_stack *a, t_stack *b)
{
	int	a_r_cnt;
	int	b_r_cnt;
	int	min_cnt;
	int	min_index;
	t_list	*cul;

	b_r_cnt = 0;
	min_cnt = a->total_size;
	min_index = b->head->index;
	cul = b->head;
		printf("HIH");
	while (b_r_cnt < b->size)
	{
		a_r_cnt = get_rotate_cnt(a, get_proximate_index(a, cul->data));
		if (a_r_cnt + b_r_cnt < min_cnt)
		{
			min_cnt = a_r_cnt + b_r_cnt;
			min_index = cul->index;
		}
		cul = cul->next;
		++b_r_cnt;
	}
	return (min_index);
}

int	get_rotate_cnt(t_stack *a, int index)
{
	int	cnt;
	t_list	*cul;

	cnt = 0;
	cul = a->head;
	while (cnt < a->size)
	{
		if (cul->index == index)
			break ;
		cul = cul->next;
		++cnt;
	}
	return (cnt);
}

//int	get_target_index(t_stack *stack, int index, int total_size)
//{
//	int	i;
//	int	term;
//	int	tmp;
//	int	target_index;
//	t_list	*cul;
//	
//	i = 0;
//	term = total_size;
//	cul = stack->head;
//	target_index = 0;
//	while (i < stack->size)
//	{
//		tmp = cul->index - index;
//		if (tmp > 0 && tmp < term)
//			target_index = cul->index;
//		cul = cul->next;
//		++i;
//		printf("target_index: %d\n", target_index);
//	}
//	return (target_index);
//}
