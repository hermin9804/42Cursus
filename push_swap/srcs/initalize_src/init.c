/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:52:56 by mher              #+#    #+#             */
/*   Updated: 2022/04/16 16:45:15 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"
#include <stdio.h>

char	*get_line_num(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 1;
	tmp = 0;
	line = 0;
	while (i < argc)
	{
		tmp = ft_strjoin(line, argv[i]);
		if (!tmp)
			exit(1);
		free(line);
		line = tmp;
		tmp = ft_strjoin(line, " ");
		if (!tmp)
			exit(1);
		free(line);
		line = tmp;
		++i;
	}
	return (line);
}

int	*get_nums(char *line, t_info *info)
{
	int		i;
	char	**strs;
	int		*nums;

	i = 0;
	strs = ft_split(line, ' ');
	if (!strs)
		exit(1);
	while (strs[i])
		++i;
	info->total_size = i;
	nums = (int *)malloc(info->total_size * sizeof(int));
	if (!nums)
		exit(1);
	i = -1;
	while (strs[++i])
		nums[i] = check_num_atoi(strs[i]);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (nums);
}

void	init_stack(t_info *info, int *nums)
{
	t_list	*tmp;

	info->a.size = 0;
	info->b.size = 0;
	info->a.head = ft_lstnew(nums[info->a.size++]);
	while (info->a.size < info->total_size)
	{
		tmp = ft_lstnew(nums[info->a.size]);
		if (!tmp)
			error_exit();
		ft_lstadd_back(&info->a.head, tmp);
		info->a.size++;
	}
	tmp = ft_lstlast(info->a.head);
	info->a.head->prev = tmp;
	tmp->next = info->a.head;
}

void	init_pivot(t_info *info, int *nums)
{
	int	size;

	size = info->total_size;
	info->min = nums[0];
	info->max = nums[size - 1];
	info->f_pivot = nums[size * 1 / 3];
	info->s_pivot = nums[size * 2 / 3];
}
