/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:53:03 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 20:36:10 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	run_op(t_info *info, char *op)
{
	if (ft_strncmp(op, "sa", 2))
		sa(info);
	else if (ft_strncmp(op, "sb", 2))
		sb(info);
	else if (ft_strncmp(op, "ss", 2))
		ss(info);
	else if (ft_strncmp(op, "pa", 2))
		pa(info);
	else if (ft_strncmp(op, "pb", 2))
		pa(info);
	else if (ft_strncmp(op, "ra", 2))
		ra(info);
	else if (ft_strncmp(op, "rb", 2))
		rb(info);
	else if (ft_strncmp(op, "rr", 2))
		rr(info);
	else if (ft_strncmp(op, "rra", 2))
		rra(info);
	else if (ft_strncmp(op, "rrb", 2))
		rra(info);
	else if (ft_strncmp(op, "rrr", 2))
		rrr(info);
}

void	checker(t_info *info)
{
	char	*op;

	while (1)
	{
		op = get_next_line(1);
		if (!op)
			break ;
		run_op(info, op);
	}
	return ;
}

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
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	init_pivot(&info, nums);
	checker(&info);
	if (!check_ascending(&info, nums))
		write(1, "KO\n", 3);
	exit(0);
}
