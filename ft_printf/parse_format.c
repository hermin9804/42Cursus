/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:16:22 by mher              #+#    #+#             */
/*   Updated: 2021/12/17 20:07:57 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	parse_format(va_list ap, const char *format)
{
	int		ret;
	t_arg_info	arg_info;

	ret = 0;
	while (*format)
	{
		init_arg_info(&arg_info);
		while (*format != '%' && *format)
			ret += ft_putchar(*(format++));
		if (*format == '%')
			ap++;
	}
	return (ret);
}
