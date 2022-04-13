/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:47:52 by mher              #+#    #+#             */
/*   Updated: 2022/04/13 12:16:34 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(const t_stack *stack)
{
	int		i;
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
