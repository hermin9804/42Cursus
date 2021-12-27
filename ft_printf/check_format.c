/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:31:15 by mher              #+#    #+#             */
/*   Updated: 2021/12/27 17:23:28 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char	*format)
{
	t_info	info;

	while (*format)
	{
		init_info(&info);
		while (*format != '%' && *format)
			++format;
		if (*(format++) == '%')
			if (fill_info(&format, &info) == -1)
				return (-1);
		if (info.type == 'c')
			if (check_char_format(&info) == -1)
				return (-1);
		if (info.type == 'd' || info.type == 'i' || info.type == 'u'
			|| info.type == 'x' || info.type == 'X' || info.type == 'p')
			if (check_nbr_format(&info) == -1)
				return (-1);
		if (info.type == 's' && info.space == 1)
			return (-1);
	}
	return (1);
}

int	check_char_format(t_info *info)
{
	if (info->alt == 1)
		return (-1);
	if (info->zero == 1)
		return (-1);
	if (info->showsign == 1)
		return (-1);
	if (info->space == 1)
		return (-1);
	if (info->prec != -1)
		return (-1);
	return (1);
}

int	check_nbr_format(t_info *info)
{
	char	t;

	t = info->type;
	if ((t == 'd' || t == 'i' || t == 'u' || t == 'p') && info->alt == 1)
		return (-1);
	if (info->zero == 1 && info->left == 1)
		return (-1);
	if ((info->showsign == 1 || info->space == 1) && info->alt == 1)
		return (-1);
	return (1);
}
