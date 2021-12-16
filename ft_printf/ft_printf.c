/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:38:16 by mher              #+#    #+#             */
/*   Updated: 2021/12/16 19:55:06 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int	ft_printf(const char *format, ...)
{
	va_list ap;
	char	p;
	char	c_tmp;
	char	*s_tmp;

	va_start(ap, format);
	while (*format)
	{
		p = *format++;
		if (p == '%')
		{
			p = *format++;
			if (p == 'c')
			{
				c_tmp = va_arg(ap, int);
				write(1, &c_tmp, 1);
			}
			if (p == 's')
			{
				s_tmp = va_arg(ap, char *);
				write(1, s_tmp, strlen(s_tmp));
			}
		}
	}
	va_end(ap);
	return (0);
}
