/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:01 by mher              #+#    #+#             */
/*   Updated: 2022/04/06 16:33:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int	size;
	t_list	*head;
}	t_stack;

// libft
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_atoi(const char *str);

void	ft_lstlink_back(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstlink_front(t_list **lst, t_list *new);

//operator
void	swap_stack(t_stack *stack);
void	sa(t_stack a);
void	sb(t_stack b);
void	ss(t_stack *a, t_stack *b);

#endif
