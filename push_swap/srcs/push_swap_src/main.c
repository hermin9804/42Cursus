/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 17:20:48 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	int	*nums;

	if (argc < 2)
		return(0);
	line = get_line_num(argc, argv);
	nums = get_nums(line, &info);
	init_stack(&info, nums);
	quick_sort(nums, 0, info.total_size - 1);
	check_dup(nums, info.total_size);
	if (check_ascending(&info, nums))
		exit(0);
	init_pivot(&info, nums);
	push_swap(&info);
	exit(0);
}
