# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 15:50:40 by mher              #+#    #+#              #
#    Updated: 2022/01/01 17:44:11 by mher             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
	
NAME		= libftprintf.a

SRCS		= \
		ft_printf.c\
		check_format.c\
		fill_info.c\
		init_info.c\
		parse_format.c\
		print_arg.c\
		print_char.c\
		print_nbr.c\
		print_string.c\
		utils.c\
		ft_strlen.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_strchr.c\

OBJS		= $(SRCS:.c=.o)
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

bonus: $(NAME)

re : fclean all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re
