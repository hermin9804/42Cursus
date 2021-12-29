/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/30 00:03:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_info
{
	char				type;
	int					prec;
	int					width;
	int					nbr_sign;
	unsigned int		alt;
	unsigned int		zero;
	unsigned int		left;
	unsigned int		showsign;
	unsigned int		space;
	unsigned int		nbr_len;
	unsigned int		nbr_base;
	int					c;
	char				*str;
	unsigned long long	nbr;
}	t_info;

int		ft_putchar(char c, int *total_len);
int		ft_putnbr(unsigned long long n, t_info *info);
int		ft_nbrlen_base(unsigned long long nbr, int base);

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, const char *format);

void	init_info(t_info *info);
void	fill_info(const char **format, t_info *info);
int		fill_flags_info(const char *format, t_info *info);
int		fill_width_prec_info(const char *format, t_info *info);
int		fill_type_info(const char *format, t_info *info);

int		print_arg(va_list ap, t_info *info);
int		print_char(int c, t_info *info);
int		putchar_info(t_info *info);

int		print_string(char *str, t_info *info);
int		print_prec_str(t_info *info);

int		print_nbr(unsigned long long nbr, t_info *info);
int		set_order_right(t_info *info);
int		set_order_left(t_info *info);
int		print_prec_nbr(t_info *info);

int		run_order(t_info *info, int f1(t_info *),
			int f2(t_info *), int f3(t_info *));
int		padding_width(t_info *info);
int		put_sign_alt(t_info *info);

int		check_format(const char	*format);
int		check_char_format(t_info *info);
int		check_nbr_format(t_info *info);

#endif
