/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:19:35 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:57:38 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	write(1, "ra\n", 3);
	rotate_stack(a);
}

void	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	rotate_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	write(1, "rr\n", 3);
	rotate_stack(a);
	rotate_stack(b);
}
