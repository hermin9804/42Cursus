/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:16:22 by mher              #+#    #+#             */
/*   Updated: 2021/12/18 17:44:23 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(va_list ap, const char *format)
{
	int		arg_len;
	int		total_len;
	t_arg_info	arg_info;

	total_len = 0;
	while (*format)
	{
		init_arg_info(&arg_info);
		while (*format != '%' && *format)
			if (ft_putchar(*(format++), &total_len) == -1)
				return (ERROR);
		if (*(format++) == '%')
		{
			if (!fill_arg_info(&format, &arg_info))
				return (ERROR);
			if (ft_strchr(TYPE, *format))
				arg_info.type = *(format++);
			else
				return (ERROR);
			arg_len = print_arg_type(ap, arg_info);
			if (arg_len == -1)
				return (ERROR);
			total_len += arg_len;
		}
	}
	return (total_len);
}
