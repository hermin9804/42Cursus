/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:18:11 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 00:56:20 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	swap_stack(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	swap_stack(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	swap_stack(a);
	swap_stack(b);
}
