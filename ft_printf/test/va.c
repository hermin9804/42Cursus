/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:38:16 by mher              #+#    #+#             */
/*   Updated: 2021/12/22 18:38:24 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
int	print_char(int	c)
{
	return (write(1, &c, 1));
}

int	print_arg(va_list ap, const char *format)
{
	char	p;
	int	ret;

	ret = 0;
	while (*format)
	{
		p = *format++;
		if (p == '%')
		{
			p = *format++;
			if (p == 'c')
				ret = print_char(va_arg(ap, int));
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int	ret;
	va_list ap;

	va_start(ap, format);
	ret = print_arg(ap, format);
	va_end(ap);
	return (0);
}

int	main(void)
{
	ft_printf("%c%c%c", 'k', 't', 'x');
	return (0);
}
