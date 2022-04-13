# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:24:10 by mher              #+#    #+#              #
#    Updated: 2022/04/13 11:32:55 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC = \
	test_utils.c \
	main.c \
	init.c \
	push_swap.c \
	list_utils.c \
	mem_utils.c \
	quick_sort.c \
	sort_utils.c \
	ft_split.c \
	str_utils.c \
	operator_p.c \
	operator_r.c \
	operator_rr.c \
	operator_s.c \
	error_exit.c \
	pop_push_swap_rotate.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
