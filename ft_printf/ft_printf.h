/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/22 19:11:01 by mher             ###   ########.fr       */
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
}	t_info;

//libft
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);

//new_utils
int		ft_putchar(char c, int *total_len);
int		ft_numlen(int num);
int		put_width(int len, t_info *info);
int		ft_putstr(char *str);

//ft_printf
int		ft_printf(const char *, ...);
int		parse_format(va_list ap, const char *format);
void	init_info(t_info *info);
int		fill_info(const char **format, t_info *info);

//print
int		print_arg(va_list *ap, t_info *info);
int		print_char(int c, t_info *info);
int		fill_flags_info(const char *format, t_info *info);
int		fill_width_info(const char *format, t_info *info);
int		print_string(char *str, t_info *info);
int		print_nbr_int(int nbr, t_info *info);

int		put_width_nbr_flags(int start, int end, t_info *info);
int		put_precision_width(int start, int end, t_info *info);
void		ft_print_nbr(int n, int *len);
int		ft_putnbr(int n);

//check_format
int		check_format(const char	*format);
int		check_char_format(t_info *info);
int		check_nbr_format(t_info *info);

#endif
