/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:12:01 by mher              #+#    #+#             */
/*   Updated: 2022/04/15 02:06:25 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>//
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int		size;
	t_list	*head;
}	t_stack;

typedef struct s_info
{
	int		total_size;
	int		max;
	int		min;
	int		f_pivot;
	int		s_pivot;
	t_stack	a;
	t_stack	b;
}	t_info;

typedef struct s_op
{
	int	r;
	int	rr;
}	t_op;

typedef struct s_rotate
{
	t_op	a;
	t_op	b;
}	t_rotate;

//push_swap
void		push_swap(t_info *info);
void		pb_smaller_than_pivot(t_info *info, int pivot);
void		pb_leave_three(t_info *info);
void		set_rotate_position(t_info *info, t_rotate rotate);
t_rotate	get_min_rotate_cnt(t_info *info);

// init
void		init_info(t_info *info, int argc, char **argv);
void		check_dup(int *nums, int size);
void		check_ascending(t_info *info, int *nums);

//sort
void		quick_sort(int *arr, int start, int end);

//operator
void		swap_stack(t_stack *stack);
t_list		*pop_stack(t_stack *stack);
void		push_stack(t_stack *dest, t_stack *from);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);
void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		pa(t_info *info);
void		pb(t_info *info);
void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);
void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

// libft
t_list		*ft_lstnew(int data);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstlast_cnt(t_list *lst, int cnt);
int			ft_atoi(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);

// error_exit
void		error_exit(void);

// test_utils
void		print_stack(const t_stack *stack);//

#endif
