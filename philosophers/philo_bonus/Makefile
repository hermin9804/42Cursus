# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 23:17:57 by mher              #+#    #+#              #
#    Updated: 2022/07/10 23:45:00 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

CTASGS	= ctags -R
TASGS   = tags

SRCS	= \
		  main.c \
		  parser.c \
		  semaphore.c \
		  sem_utils.c \
		  routine.c \
		  routine_utils.c \
		  simulation.c \
		  observer.c \
		  utils.c \

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	$(CTASGS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
