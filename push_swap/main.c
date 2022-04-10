/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/11 01:07:20 by mher             ###   ########.fr       */
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
		printf("%d", p->data);
		printf("\n");
		p = p->next;
		i++;
	}
}

void	init_info(t_info *info, int *nums)
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
		ft_lstadd_front(&info->a.head, tmp);
		info->a.size++;
		i++;
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

	print_stack(&info.a);
	print_stack(&info.b);

	push_swap(&info);
	print_stack(&info.a);
	print_stack(&info.b);
}
