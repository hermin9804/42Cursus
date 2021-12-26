/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/26 18:54:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>//test

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_info
{
	char			type;
	int			prec;
	int			width;
	int			alt;
	int			zero;
	int			left;
	int			showsign;
	int			space;
	int			nbr_sign;
	unsigned int		nbr_len;
	unsigned int		nbr_base;
	unsigned long long	nbr;
	char			*str;
	void			*contant;
	int			c;
}	t_info;

//new_utils
int		ft_putchar(char c, int *total_len);
int		ft_putnbr(unsigned long long n, t_info *info);
int		ft_nbrlen_base(unsigned long long nbr, int base);

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
int		putchar_info(t_info *info);

int		print_string(char *str, t_info *info);
int		print_prec_str(t_info *info);

int		print_nbr(unsigned long long nbr, t_info *info);
int		set_order_right(t_info *info);
int		set_order_left(t_info *info);
int		print_prec_nbr(t_info *info);

int		run_function_order(t_info *info, int f1(t_info *), int f2(t_info *), int f3(t_info *));
int		padding_width(t_info *info);
int		put_sign_alt(t_info *info);

//check_format
int		check_format(const char	*format);
int		check_char_format(t_info *info);
int		check_nbr_format(t_info *info);

#endif
