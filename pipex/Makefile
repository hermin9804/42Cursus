# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 15:50:40 by mher              #+#    #+#              #
#    Updated: 2022/05/08 01:19:50 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
	
NAME	= pipex

RM	= rm -f
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

FT_DIR	= ./lib/Libft
GNL_DIR	= ./lib/libgnl	
FT 	= ft
GNL	= gnl

M_SRCS	= \
	  pipex.c \
	  path.c \
	  fd_handling.c \
	  error_handling.c \

B_SRCS	= \
	  pipex_bonus.c \
	  path_bonus.c \
	  here_doc_bonus.c \
	  fd_handling_bonus.c \
	  error_handling_bonus.c \

M_OBJS	= $(M_SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(B_OBJS)
else
	OBJECTS = $(M_OBJS)
endif

$(NAME) : $(OBJECTS)
	$(MAKE) -C $(FT_DIR) 
	$(MAKE) -C $(GNL_DIR) 
	$(CC) $(CFLAGS) -o  $@ $^ \
		-L$(FT_DIR) -l$(FT) \
		-L$(GNL_DIR) -l$(GNL)

all : $(NAME)

bonus : $(B_OBJS)
	make WITH_BONUS=1 all

clean :
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(GNL_DIR)
	$(RM) $(M_OBJS)

fclean : clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
