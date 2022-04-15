# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:24:10 by mher              #+#    #+#              #
#    Updated: 2022/04/16 02:58:54 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CHECKER	= checker

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

FT_DIR	= ./lib/Libft
GNL_DIR	= ./lib/libgnl	
FT 	= ft
GNL	= gnl

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

INITALIZE_DIR = ./srcs/initalize_src
INITALIZE_SRC = \
	$(INITALIZE_DIR)/init.c \
	$(INITALIZE_DIR)/check.c \
	$(INITALIZE_DIR)/quick_sort.c \
	$(INITALIZE_DIR)/error_exit.c \

PUSH_SWAP_DIR = ./srcs/push_swap_src
PUSH_SWAP_SRC = \
	$(OPERATOR_SRC) \
	$(DATA_STRUCT_SRC) \
	$(INITALIZE_SRC) \
	$(PUSH_SWAP_DIR)/main.c \
	$(PUSH_SWAP_DIR)/push_swap.c \
	$(PUSH_SWAP_DIR)/set_position.c \
	$(PUSH_SWAP_DIR)/get_min_rotate_cnt.c \

CHECKER_DIR =  ./srcs/checker_src
CHECKER_SRC = \
	$(OPERATOR_SRC) \
	$(DATA_STRUCT_SRC) \
	$(INITALIZE_SRC) \
	$(CHECKER_DIR)/checker.c \


PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(PUSH_SWAP_OBJ)
	$(MAKE) -C $(FT_DIR) 
	$(CC) $(CFLAGS) -o $@ $^ \
		-L$(FT_DIR) -l$(FT) 

$(CHECKER) : $(CHECKER_OBJ)
	$(MAKE) -C $(FT_DIR) 
	$(MAKE) -C $(GNL_DIR) 
	$(CC) $(CFLAGS) -o $@ $^ \
		-L$(FT_DIR) -l$(FT) \
		-L$(GNL_DIR) -l$(GNL)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	
clean:
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	rm -f $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)

fclean: clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re
