/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:16:22 by mher              #+#    #+#             */
/*   Updated: 2021/12/22 19:14:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(va_list ap, const char *format)
{
	int		arg_len;
	int		total_len;
	t_info	info;

	total_len = 0;
	while (*format)
	{
		init_info(&info);
		while (*format != '%' && *format)
			if (ft_putchar(*(format++), &total_len) == -1)
				return (ERROR);
		if (*format == '%')
		{
			++format;
			if (fill_info(&format, &info) == -1)
				return (ERROR);
			arg_len = print_arg(&ap, &info);
			if (arg_len == -1)
				return (ERROR);
			total_len += arg_len;
		}
	}
	return (total_len);
}
