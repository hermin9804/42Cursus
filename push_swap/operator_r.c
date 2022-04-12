/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:19:35 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:19:51 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	printf("ra\n");
	rotate_stack(a);
}

void	rb(t_stack *b)
{
	printf("rb\n");
	rotate_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	rotate_stack(a);
	rotate_stack(b);
}
