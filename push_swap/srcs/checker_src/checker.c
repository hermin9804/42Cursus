/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:53:03 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 17:57:21 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	run_op(t_info *info, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(info, 'c');
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(info, 'c');
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(info, 'c');
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(info, 'c');
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(info, 'c');
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(info, 'c');
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(info, 'c');
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(info, 'c');
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(info, 'c');
	else if (!ft_strncmp(op, "rrb\n", 4))
		rra(info, 'c');
	else if (!ft_strncmp(op, "rrr\n", 4))
		rrr(info, 'c');
	else
		error_exit("Error\n");
}

static void	checker(t_info *info)
{
	char	*op;

	op = 0;
	while (1)
	{
		op = get_next_line(1);
		if (!op)
			break ;
		run_op(info, op);
		free(op);
	}
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
	checker(&info);
	if (info.b.size == 0 && check_ascending(&info, nums))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}
