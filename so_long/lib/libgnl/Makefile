# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 18:07:13 by mher              #+#    #+#              #
#    Updated: 2022/03/26 18:33:33 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRC_DIR = ./src
SRC = \
	$(SRC_DIR)/get_next_line.c\
	$(SRC_DIR)/get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@ar crsu $(NAME) $@
		
clean:
	    rm -f $(OBJ)

fclean: clean
	    rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
