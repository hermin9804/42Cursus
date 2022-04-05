/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:48 by mher              #+#    #+#             */
/*   Updated: 2022/04/05 22:09:05 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_input(int argc, char **argv, t_stack *a)
{
	int		i;
	t_list	*new;

	i = 1;
	a->head = ft_lstnew(ft_atoi(argv[i++]));
	++a->size;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i++]));
		if (!new) //error
			return ;
		new->next = a->head;
		a->head->prev = new;
		a->head = new;
		++a->size;
	}

	while (a->head)
	{
		printf("%d ", a->head->data);
		a->head = a->head->next;
	}
}

//void	sa(t_stack *a)
//{
//}

//void	sb(t_stack *a, t_stack *b)
//{
//
//}
//
//
//void	push_swap(t_stack *a, t_stack *b)
//{
//
//}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a.size = 0;
	b.size = 0;
	parse_input(argc, argv, &a);
//	push_swap(a, b);

//	printf("\n%d", a.size); //test
}
