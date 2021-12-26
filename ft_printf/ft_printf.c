/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:38:16 by mher              #+#    #+#             */
/*   Updated: 2021/12/26 14:24:56 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	ret;
	va_list ap;

	if (!format)
		return (-1);
	if (check_format(format) == -1)
		return (-1);
	va_start(ap, format);
	ret = parse_format(ap, format);
	va_end(ap);
	return (ret);
}
