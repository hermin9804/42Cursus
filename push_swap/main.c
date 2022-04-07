/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/07 14:25:20 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(const t_stack *stack)
{
	int	i;
	t_list	*p;

	 i = 0;
	p = stack->head;
	printf("size %d : ", stack->size);
	while (i < stack->size)
	{
		printf("%d ", p->data);
		p = p->next;
		i++;
	}
	printf("\n");
}

void	parse_input(char **argv, t_stack *stack)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	stack->head = ft_lstnew(ft_atoi(argv[i++]));
	stack->size++;
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoi(argv[i++]));
		if (!tmp) // return error code -1??
			return ;
		ft_lstadd_front(&stack->head, tmp);
		stack->size++;
	}
	tmp = ft_lstlast(stack->head);
	stack->head->prev = tmp;
	tmp->next = stack->head;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.size = 0;
	b.size = 0;
	if (argc < 2)
		return (0);
	parse_input(argv, &a);
	print_stack(&a);

	rra(&a);
	print_stack(&a);
}
