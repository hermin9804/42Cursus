/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:14:30 by mher              #+#    #+#             */
/*   Updated: 2022/04/06 16:17:51 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
}

void	push_stack(t_stack *dest, t_stack *from)
(

)

void	sa(t_stack *a)
{
	swap_stack(a)
}

void	sb(t_stack *b)
{
	swap_stack(b)
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a)
	swap_stack(b)
}
