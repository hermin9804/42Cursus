/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:14:30 by mher              #+#    #+#             */
/*   Updated: 2022/04/07 20:07:16 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
	tmp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp;
}

void	push_stack(t_stack *dest, t_stack *from)
{
	if (from->size == 0)
		return ;
	if (dest->size == 0)
	{
		dest->head = pop_stack(from);
		dest->size++;
		return ;
	}
	ft_lstadd_front(&dest->head, pop_stack(from));
	dest->size++;
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

void	rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}

void	sa(t_stack *a)
{
	swap_stack(a);
}

void	sb(t_stack *b)
{
	swap_stack(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	push_stack(b, a);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
}

void	rb(t_stack *b)
{
	rotate_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	rra(t_stack *a)
{
	reverse_rotate_stack(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
