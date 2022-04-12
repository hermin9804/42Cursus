/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:18:11 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:18:34 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	printf("sa\n");
	swap_stack(a);
}

void	sb(t_stack *b)
{
	printf("sb\n");
	swap_stack(b);
}

void	ss(t_stack *a, t_stack *b)
{
	printf("ss\n");
	swap_stack(a);
	swap_stack(b);
}
