/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:18:52 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:19:15 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	printf("pa\n");
	push_stack(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	printf("pb\n");
	push_stack(b, a);
}
