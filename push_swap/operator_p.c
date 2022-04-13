/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:18:52 by mher              #+#    #+#             */
/*   Updated: 2022/04/14 02:12:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	write(1, "pa\n", 3);
	push_stack(&info->a, &info->b);
}

void	pb(t_info *info)
{
	write(1, "pb\n", 3);
	push_stack(&info->b, &info->a);
}
