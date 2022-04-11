/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:01 by mher              #+#    #+#             */
/*   Updated: 2022/04/11 18:34:16 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_op
{
	int	r;
	int	rr;
}	t_op;

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
	t_list	*head;
}	t_stack;

typedef struct s_anchor
{
	int	data;
	t_list	*p;
}	t_anchor;

typedef struct s_info
{
	t_stack		a;
	t_stack		b;
	t_anchor	*anchor;
	int		total_size;
}	t_info;

// test
void	print_stack(const t_stack *stack);

// libft
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
int	ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

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

//sort
void	quick_sort(t_anchor *arr, int start, int end);

//utils
size_t	ft_abs(long long x);
t_list	*ft_lstlast_cnt(t_list *lst, int cnt);

//push_swap
void	first_setting(t_info *info);
void	greedy_sort(t_info *info);
void	set_position(t_info *info, t_op op);
t_op	get_min_operation_cnt(t_info *info);
void	push_swap(t_info *info);
void	set_ascending(t_info *info);

//void	push_swap(t_info *info);
//int	get_min_operation_num(t_info *info);
//int	get_proximate_num(t_stack *stack, int data);
//void	set_position(t_info *info, int min_operation_num);
//int	get_rotate_cnt(t_stack *stack, int proximate_num);
//void	set_ascending(t_info *info);
//t_op	get_min_op(t_info *info);
//t_op	get_op_cnt(t_stack *stack, int proximate_num);

#endif
