/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:14:30 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:56:59 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	write(1, "rra\n", 4);
	reverse_rotate_stack(a);
}

void	rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	reverse_rotate_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
