/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/19 20:34:02 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define TYPE "csdiupxX%"
# define FLAG "#0-+ "

typedef struct s_arg_info
{
	int	alternate;	//#
	int	zero;		//0
	int	minus;		//-
	int	plus;		//+
	int	space;		//' '
	int	width;		//
	int	precision;	//.
	char	type;
	int	nbr_base;
	int	nbr_sign;
}	t_arg_info;

//libft
size_t	ft_strlen(const char *s);
int	ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *str);

//new_utils
int	ft_putchar(char c, int *total_len);
int	ft_numlen(int num);

//ft_printf
int	ft_printf(const char *, ...);
int	parse_format(va_list ap, const char *format);
void	init_arg_info(t_arg_info *arg_info);
int	fill_arg_info(const char **format, t_arg_info *arg_info);

//print
int	print_arg(va_list ap, t_arg_info arg_info);
int	print_char(char c, t_arg_info arg_info);



#endif
