/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:14:30 by mher              #+#    #+#             */
/*   Updated: 2022/04/14 02:13:43 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	write(1, "rra\n", 4);
	reverse_rotate_stack(&info->a);
}

void	rrb(t_info *info)
{
	write(1, "rrb\n", 4);
	reverse_rotate_stack(&info->b);
}

void	rrr(t_info *info)
{
	write(1, "rrr\n", 4);
	reverse_rotate_stack(&info->a);
	reverse_rotate_stack(&info->b);
}
