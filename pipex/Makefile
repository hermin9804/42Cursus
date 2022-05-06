# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 15:50:40 by mher              #+#    #+#              #
#    Updated: 2022/05/06 17:01:03 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
	
NAME	= pipex

SRCS	= \
	  main.c \
	  init.c \
	  path.c \
	  fd_handling.c \
	  error_exit.c \
	  error_handling_funs.c \
	  get_next_line.c \
	  str_utils1.c \
	  str_utils2.c \
	  ft_split.c \

OBJS	= $(SRCS:.c=.o)
RM	= rm -f
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o  $@ $^ 

all : $(NAME)

bonus : $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re
