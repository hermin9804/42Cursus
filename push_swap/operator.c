/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:14:30 by mher              #+#    #+#             */
/*   Updated: 2022/04/06 19:40:24 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list *head)
{
	int	tmp;

	tmp = head->data;
	head->data = head->next->data;
	head->next->data = tmp;
}

void	push_stack(t_stack *dest, t_stack *from)
{
	if (dest->size == 0)
	{
		dest->head = pop_stack(from);
		return ;
	}
	ft_lstadd_front(&dest->head, pop_stack(from));
}

t_list	*pop_stack(t_stack *stack)
{
	t_list *pop;

	pop = stack->head;
	stack->head->prev->next = stack->head->next;
	stack->head->next->prev = stack->head->prev;
	stack->head = stack->head->next;
	stack->size--;
	pop->next = 0;
	pop->prev = 0;
	return (pop);
}

void	sa(t_list *a)
{
	swap_stack(a);
}

void	sb(t_list *b)
{
	swap_stack(b);
}

void	ss(t_list *a, t_list *b)
{
	swap_stack(a);
	swap_stack(b);
}
