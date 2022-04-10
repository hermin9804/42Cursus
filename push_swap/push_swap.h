/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:01 by mher              #+#    #+#             */
/*   Updated: 2022/04/10 16:52:14 by mher             ###   ########.fr       */
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
	int		index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int	size;
	int	total_size;
	t_list	*head;
}	t_stack;

typedef struct s_tag
{
	int	data;
	t_list	*anchor;
}	t_tag;

typedef struct s_tags
{
	int	size;
	t_tag	*arr;
}	t_tags;

// test
void	print_stack(const t_stack *stack);
void	print_tags(const t_tags *tags);

// libft
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
int	ft_atoi(const char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);

//operator
void	swap_stack(t_stack *stack);
t_list	*pop_stack(t_stack *stack);
void	push_stack(t_stack *dest, t_stack *from);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//utils
int	ft_abs(int x);
t_list	*ft_lstlast_cnt(t_list *lst, int cnt);

//sort
void	quick_sort(t_tag *arr, int start, int end);

//push_swap
void	push_swap(t_stack *a, t_stack *b);
int	get_proximate_index(t_stack *a, int index);
void	set_position(t_stack *a, t_stack *b, int min_index);
int	get_min_index(t_stack *a, t_stack *b);
int	get_rotate_cnt(t_stack *a, int index);




int	get_target_index(t_stack *stack, int index, int total_size);

#endif
