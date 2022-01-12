/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:31:15 by mher              #+#    #+#             */
/*   Updated: 2022/01/13 00:36:33 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char	*format)
{
	t_info	info;

	if (format == NULL)
		return (-1);
	while (*format)
	{
		init_info(&info);
		while (*format != '%' && *format)
			++format;
		if (*(format++) == '%')
			if (fill_info(&format, &info) == -1)
				return (-1);
	}
	return (1);
}
