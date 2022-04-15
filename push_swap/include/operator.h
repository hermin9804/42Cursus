/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:19:05 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 17:50:50 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "unistd.h"
# include "data_struct.h"

void		swap_stack(t_stack *stack);
t_list		*pop_stack(t_stack *stack);
void		push_stack(t_stack *dest, t_stack *from);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		pa(t_info *info);
void		pb(t_info *info);
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

#endif
