/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/08 18:10:37 by mher             ###   ########.fr       */
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
		//printf("%d %d %p", p->data, p->index, p);
		printf("\n");
		p = p->next;
		i++;
	}
}

void	print_tags(const t_tags *tags)
{
	int	i;

	i = 0;
	printf("tags->arr[i] data :");
	while (i < tags->size)
		printf("%d ", tags->arr[i++].data);
	printf("\n");
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
	//	if (is_alnum(argv[i]))
	//		exit(1);
	//	if (is_dup(argv[i]))
	//		exit(1);
		++i;
	}
	return (i - 1);
}

void	init_stack(t_stack *stack, t_tags *tags)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	stack->size = 0;
	if (!tags)
		return ;
	stack->head = ft_lstnew(tags->arr[i++].data);
	stack->size++;
	while (i < tags->size)
	{
		tmp = ft_lstnew(tags->arr[i].data);
		if (!tmp)
			exit(1);//
		ft_lstadd_front(&stack->head, tmp);
		i++;
		stack->size++;
	}
	tmp = ft_lstlast(stack->head);
	stack->head->prev = tmp;
	tmp->next = stack->head;
	stack->total_size = stack->size;
}

void	init_tags(t_tags *tags, char **argv)
{
	int	i;
	int	j;

	tags->arr = (t_tag *)malloc(tags->size* sizeof(t_tag));
	if (!tags->arr)
		exit(1);
	i = 0;
	j = 1;
	while (i < tags->size)
	{
		tags->arr[i].data = ft_atoi(argv[j]);
		++i;
		++j;
	}
}
void	link_tag_to_list(t_tags *tags, t_stack *stack)
{
	int	i;
	t_list	*p;

	i = 0;
	p = stack->head->prev;
	while (i < tags->size)
	{
		tags->arr[i].anchor = p;
		++i;
		p = p->prev;
	}
}

void	map_index(t_tags *tags)
{
	int	i;
	
	i = 0;
	while (i < tags->size)
	{
		tags->arr[i].anchor->index = i;
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_tags	tags;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	tags.size = check_input(argc, argv);
	init_tags(&tags, argv);
	init_stack(&a, &tags);
	init_stack(&b, 0);
	link_tag_to_list(&tags, &a);
	quick_sort(tags.arr , 0, tags.size - 1);
	map_index(&tags);
	push_swap(&a, &b);
}
