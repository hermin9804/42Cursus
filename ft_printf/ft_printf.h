/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:39:12 by mher              #+#    #+#             */
/*   Updated: 2021/12/17 20:07:23 by mher             ###   ########.fr       */
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

typedef struct s_arg_info
{
	char	type;
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	alternate;
	int	space;
	int	plus;
	int	nbr_base;
	int	nbr_sign;
}	t_arg_info;

size_t	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_printf(const char *, ...);
int	parse_format(va_list ap, const char *format);
void	init_arg_info(t_arg_info *arg_info);

#endif
