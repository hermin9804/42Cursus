/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/11 18:36:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(const t_stack *stack)
{
	int	i;
	t_list	*p;

	i = 0;
	p = stack->head;
	printf("print-stack, size %d \n", stack->size);
	while (i < stack->size)
	{
		printf("%d %d", p->data, p->index);
		printf("\n");
		p = p->next;
		i++;
	}
}

void	print_anchor(const t_info *info)
{
	int	i;

	i = 0;
	printf("info->anchor[i].data :");
	while (i < info->total_size)
	{
		printf("%d ", info->anchor[i].data);
		++i;
	}
	printf("\n");
}

void	init_anchor_data(t_info *info, int *nums)
{
	int	i;

	i = 0;
	info->anchor = (t_anchor *)malloc(info->total_size * sizeof(t_anchor));
	if (!info->anchor)
		exit(1);//
	while (i < info->total_size)
	{
		info->anchor[i].data = nums[i];
		i++;
	}
}


void	mapping_index(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->total_size)
	{
		info->anchor[i].p->index = i;
		++i;
	}
}

void	link_anchor_stack(t_info *info)
{
	int	i;
	t_list	*cul;

	i = 0;
	cul = info->a.head;
	while (i < info->total_size)
	{
		info->anchor[i].p = cul;
		cul = cul->next;
		++i;
	}
}

void	init_stack(t_info *info, int *nums)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	info->a.size = 0;
	info->b.size = 0;
	info->a.head = ft_lstnew(nums[i++]);
	info->a.size++;
	while (i < info->total_size)
	{
		tmp = ft_lstnew(nums[i]);
		if (!tmp)
			exit(1);//
		ft_lstadd_back(&info->a.head, tmp);
		info->a.size++;
		++i;;
	}
	tmp = ft_lstlast(info->a.head);
	info->a.head->prev = tmp;
	tmp->next = info->a.head;
}

char	*get_line(int argc, char **argv)
{
	int	i;
	char	*tmp;
	char	*line;

	i = 1;
	tmp = 0;
	line = 0;
	while (i < argc)
	{
		tmp = ft_strjoin(line, argv[i]);
		if (!tmp)
			exit(1);//
		free(line);
		line = tmp;
		tmp = ft_strjoin(line, " ");
		if (!tmp)
			exit(1);//
		free(line);
		line = tmp;
		++i;
	}
	return (line);
}

int	*get_nums(char *line, t_info *info)
{
	int	i;
	char	**strs;
	int	*nums;

	i = 0;
	strs = ft_split(line, ' ');
	if (!strs)
		exit(1);
	while (strs[i])
		++i;
	info->total_size = i;
	nums = (int *)malloc(info->total_size * sizeof(int));
	i = 0;
	while (strs[i])
	{
		nums[i] = ft_atoi(strs[i]);
		++i;
	}
	i = 0;
	while (strs[i])
		free(strs[i++]);
	return (nums);
}

void	init_info(t_info *info, int *nums)
{
	size_t	i;
	t_list	*tmp;

	init_anchor_data(info, nums);
	init_stack(info, nums);
	link_anchor_stack(info);
	quick_sort(info->anchor, 0, info->total_size - 1);
	mapping_index(info);
}

int	main(int argc, char **argv)
{
	char	*line;
	int	*nums;
	t_info	 info;

	if (argc < 2)
		exit(1);
	line = get_line(argc, argv);
	nums = get_nums(line, &info);
	init_info(&info, nums);
	push_swap(&info);
//	print_stack(&info.a);
}

