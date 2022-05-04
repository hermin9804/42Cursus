# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 15:50:40 by mher              #+#    #+#              #
#    Updated: 2022/05/04 18:32:25 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
	
NAME	= pipex

FT_DIR	= ./Libft
FT 	= ft

SRCS	= \
	  main.c\

OBJS	= $(SRCS:.c=.o)
RM	= rm -f
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(MAKE) -C $(FT_DIR) 
	$(CC) $(CFLAGS) -o  $@ $^ \
		-L$(FT_DIR) -l$(FT) 


all : $(NAME)

bonus : $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

clean :
	$(MAKE) -C $(FT_DIR) 
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C $(FT_DIR)
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re
