/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:31:15 by mher              #+#    #+#             */
/*   Updated: 2021/12/20 18:38:05 by mher             ###   ########.fr       */
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
			if (fill_info(&format, &info) == ERROR)
				return (ERROR);
		if (info.type == 'c' || info.type == 's')
		{
			if (check_char_format(&info) == -1)
				return (ERROR);
		}
		else if (info.type != '%')
		{
			if (check_nbr_format(&info) == -1)
				return (ERROR);
		}
	}
	return (TRUE);
}

int	check_char_format(t_info *info)
{
	if (info->alternate == 1)
		return (ERROR);
	if (info->zero == 1)
		return (ERROR);
	if (info->plus == 1)
		return (ERROR);
	if (info->space == 1)
		return (ERROR);
	if (info->precision != -1)
		return (ERROR);
	return (TRUE);
}

int	check_nbr_format(t_info *info)
{
	char	type;
	int		alte;

	type = info->type;
	alte = info->alternate;
	if ((type == 'd' || type == 'i' || type == 'u' || type == 'p') && alte)
		return (ERROR);
	if (info->zero == 1 && info->minus == 1)
		return (ERROR);
	return (TRUE);
}
