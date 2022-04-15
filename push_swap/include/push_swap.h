/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:01 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 17:46:16 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>//
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "data_struct.h"
# include "operator.h"
# include "../lib/libft/include/libft.h"

//push_swap
void		push_swap(t_info *info);
void		pb_smaller_than_pivot(t_info *info, int pivot);
void		pb_leave_three(t_info *info);
void		set_rotate_position(t_info *info, t_rotate rotate);
t_rotate	get_min_rotate_cnt(t_info *info);

// init
void		init_info(t_info *info, int argc, char **argv);
void		check_dup(int *nums, int size);
void		check_ascending(t_info *info, int *nums);
int		check_num_atoi(const char *str);

//sort
void		quick_sort(int *arr, int start, int end);

// error_exit
void		error_exit(void);

#endif
