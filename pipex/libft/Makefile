# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 13:44:52 by mher              #+#    #+#              #
#    Updated: 2022/03/27 02:14:26 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC 	= gcc
CFLAGS 	= -Wall -Wextra -Werror

INCLUDE = -I./include

SRC_DIR = ./src
SRC = \
	$(SRC_DIR)/ft_atoi.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_isalnum.c \
	$(SRC_DIR)/ft_isalpha.c \
	$(SRC_DIR)/ft_isascii.c \
	$(SRC_DIR)/ft_isdigit.c \
	$(SRC_DIR)/ft_isprint.c \
	$(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_memchr.c \
	$(SRC_DIR)/ft_memcmp.c \
	$(SRC_DIR)/ft_memcpy.c \
	$(SRC_DIR)/ft_memmove.c \
	$(SRC_DIR)/ft_memset.c \
	$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/ft_putnbr_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_strjoin.c \
	$(SRC_DIR)/ft_strlcat.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_strmapi.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_strnstr.c \
	$(SRC_DIR)/ft_strrchr.c \
	$(SRC_DIR)/ft_strtrim.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_tolower.c \
	$(SRC_DIR)/ft_striteri.c \
	$(SRC_DIR)/ft_toupper.c

B_SRC= \
	$(SRC_DIR)/ft_lstnew.c \
	$(SRC_DIR)/ft_lstadd_front.c \
	$(SRC_DIR)/ft_lstsize.c \
	$(SRC_DIR)/ft_lstlast.c \
	$(SRC_DIR)/ft_lstadd_back.c \
	$(SRC_DIR)/ft_lstdelone.c \
	$(SRC_DIR)/ft_lstclear.c \
	$(SRC_DIR)/ft_lstiter.c \
	$(SRC_DIR)/ft_lstmap.c

OBJ	= $(SRC:.c=.o)

B_OBJ	= $(B_SRC:.c=.o)


$(NAME): $(OBJ)

bonus: $(OBJ) $(B_OBJ)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@ar crsu $(NAME) $@

all: $(NAME)
		
clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
