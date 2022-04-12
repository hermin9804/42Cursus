/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:14:30 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:20:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	printf("rra\n");
	reverse_rotate_stack(a);
}

void	rrb(t_stack *b)
{
	printf("rrb\n");
	reverse_rotate_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	printf("rrr\n");
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
