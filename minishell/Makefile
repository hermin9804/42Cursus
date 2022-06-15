NAME = minishell

SRCS		=	main.c \
			./builtins/ft_pwd.c \
			./builtins/ft_env.c \
			./builtins/ft_cd.c \
			./builtins/ft_echo.c \
			./builtins/ft_export.c \
			./builtins/ft_export_check_valid.c \
			./builtins/ft_export_no_arg_utils.c \
			./builtins/ft_unset.c \
			./builtins/ft_exit.c \
			./builtins/ft_getenv.c \
			./builtins/env_utils.c \
			./builtins/cd_utils.c \
			./executor/executor.c \
			./executor/executor_utils.c \
			./executor/path.c \
			./executor/redirection.c \
			./executor/wait_child.c \
			./executor/close_unused_fd.c \
			./executor/check_valid_syntax.c \
			./executor/heredoc.c \
			./executor/tmp_file.c \
			./executor/io_file_open.c \
			./executor/init_and_clear_cmd.c \
			./utiles/ft_isalnum.c \
			./utiles/ft_itoa.c \
			./utiles/ft_split.c \
			./utiles/ft_strcmp.c \
			./utiles/ft_strjoin.c \
			./utiles/ft_strlen.c \
			./utiles/ft_strncmp.c \
			./utiles/ft_strlcpy.c \
			./utiles/ft_strdup.c \
			./utiles/ft_atoi.c \
			./utiles/ft_isspace.c \
			./utiles/ft_putstr_fd.c \
			./utiles/ft_system_calls.c \
			./utiles/ft_system_calls2.c \
			./utiles/is_exist_file.c \
			./utiles/exit_with_error.c \
			./utiles/signal.c \
			./parser/ft_split_argc.c \
			./parser/ft_strjoin_char.c \
			./parser/parse_set_quotes.c \
			./parser/parse.c \
			./parser/replace.c \
			./struct/cmd.c \
			./parser/replace_util.c \
			./parser/argc_checker.c

OBJS		= $(SRCS:%.c=%.o)

CC = gcc $(DEBUG)
CFLAGS = -Werror -Wall -Wextra
# SAN = -fsanitize=address -g3
DEBUG = -g
#READLINE_LIB 	= -lreadline -L/opt/homebrew/opt/readline/lib
#READLINE_INC	= -I/opt/homebrew/opt/readline/include
READLINE_LIB 	= -lreadline -L${HOME}/.brew/opt/readline/lib
READLINE_INC	= -I${HOME}/.brew/opt/readline/include

FT_DIR	= ./libft
FT 	= ft

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(READLINE_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean		:
		rm -f $(OBJS)

fclean		:	clean
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
