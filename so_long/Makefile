# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 18:07:13 by mher              #+#    #+#              #
#    Updated: 2022/03/27 01:55:47 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit

LIBFT_DIR = ./lib/Libft
LIBGNL_DIR = ./lib/libgnl	
LIBMLX_DIR =./lib/libmlx
FT = ft
GNL = gnl
MLX = mlx

INCLUDE = -I./include

SRC_DIR = ./src
SRC = \
	$(SRC_DIR)/so_long.c #test

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) 
	$(MAKE) -C $(LIBGNL_DIR) 
	$(MAKE) -C $(LIBMLX_DIR)
	$(CC) $(CFLAGS) -o $@ $^ \
		-L$(LIBFT_DIR) -l$(FT) \
		-L$(LIBGNL_DIR) -l$(GNL) \
		-L$(LIBMLX_DIR) -l$(MLX) $(MLX_FLAGS)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

all: $(NAME)
		
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBGNL_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(LIBGNL_DIR)
	rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
