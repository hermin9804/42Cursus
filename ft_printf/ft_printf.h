/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/24 03:38:21 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>//test

# include <stdlib.h> //?
# include <stdarg.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define TYPE "csdiupxX%"
# define FLAG "#0-+ "

typedef struct s_info
{
	int		prec;		//.
	int		width;		//
	int		alt;		//#
	int		zero;		//0
	int		left;		//-
	int		showsign;	//+
	int		space;		//' '
	char		type;
	int		nbr_len;
	int		nbr_base;
	int		nbr_sign;
	long long	nbr;
}	t_info;

//libft
size_t		ft_strlen(const char *s);
int		ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);

//new_utils
int		ft_putchar(char c, int *total_len);
int		ft_numlen(int num);
int		ft_putstr(char *str);

//ft_printf
int		ft_printf(const char *, ...);
int		parse_format(va_list ap, const char *format);

//t_info
void		init_info(t_info *info);
int		fill_info(const char **format, t_info *info);
int		fill_flags_info(const char *format, t_info *info);
int		fill_width_info(const char *format, t_info *info);

//print
int		print_arg(va_list *ap, t_info *info);
int		print_char(int c, t_info *info);
int		print_string(char *str, t_info *info);
int		char_type_padding(int len, t_info *info);

int		print_nbr(long long nbr, t_info *info);
int		set_order_right(t_info *info);
int		set_order_left(t_info *info);
int		run_function_order(t_info *info, int f1(t_info *), int f2(t_info *), int f3(t_info *));
int		ft_putnbr(long long n);
int		padding_width(t_info *info);
int		padding_prec_putnbr(t_info *info);
int		put_sign(t_info *info);

//check_format
int		check_format(const char	*format);
int		check_char_format(t_info *info);
int		check_nbr_format(t_info *info);

#endif
