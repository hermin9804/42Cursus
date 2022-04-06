/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/06 16:33:27 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(char **argv, t_stack *a)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	a->head = ft_lstnew(ft_atoi(argv[i++]));
	++a->size;
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoi(argv[i++]));
		if (!tmp) //error
			return ;
		tmp->next = a->head;
		a->head->prev = tmp;
		a->head = tmp;
		++a->size;
	}
	tmp = ft_lstlast(a->head);
	a->head->prev = tmp;
	tmp->next = a->head;
}

void	print_stack(t_stack *stack)
{
	t_list	*p;

	p = stack->head->next;
	printf("%d ", stack->head->data);
	while (p != stack->head)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a.size = 0;
	b.size = 0;
	parse_input(argv, &a);
	print_stack(&a);
	swap_stack(&a);
	print_stack(&a);

	//printf("\n%d", a.size); //test
}
