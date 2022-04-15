# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:24:10 by mher              #+#    #+#              #
#    Updated: 2022/04/15 18:12:44 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

FT_DIR	= ./lib/Libft
FT 	= ft

INCLUDE = -I./include

DATA_STRUCT_DIR = ./srcs/data_struct_src
DATA_STRUCT_SRC = \
	$(DATA_STRUCT_DIR)/list_utils.c \

OPERATOR_DIR = ./srcs/operator_src
OPERATOR_SRC = \
	$(OPERATOR_DIR)/operator_s.c \
	$(OPERATOR_DIR)/operator_p.c \
	$(OPERATOR_DIR)/operator_r.c \
	$(OPERATOR_DIR)/operator_rr.c \
	$(OPERATOR_DIR)/pop_push_swap_rotate.c \

PUSH_SWAP_DIR = ./srcs/push_swap_src
PUSH_SWAP_SRC = \
	$(OPERATOR_SRC) \
	$(DATA_STRUCT_SRC) \
	$(PUSH_SWAP_DIR)/main.c \
	$(PUSH_SWAP_DIR)/init.c \
	$(PUSH_SWAP_DIR)/push_swap.c \
	$(PUSH_SWAP_DIR)/set_position.c \
	$(PUSH_SWAP_DIR)/quick_sort.c \
	$(PUSH_SWAP_DIR)/check.c \
	$(PUSH_SWAP_DIR)/error_exit.c \
	$(PUSH_SWAP_DIR)/get_min_rotate_cnt.c \

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJ)
	$(MAKE) -C $(FT_DIR) 
	$(CC) $(CFLAGS) -o $@ $^ \
		-L$(FT_DIR) -l$(FT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	
clean:
	$(MAKE) clean -C $(FT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(FT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
