/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:18:11 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 16:44:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	sa(t_info *info)
{
	write(1, "sa\n", 3);
	swap_stack(&info->a);
}

void	sb(t_info *info)
{
	write(1, "sb\n", 3);
	swap_stack(&info->b);
}

void	ss(t_info *info)
{
	write(1, "ss\n", 3);
	swap_stack(&info->a);
	swap_stack(&info->b);
}
