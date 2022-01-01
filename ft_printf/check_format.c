/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:31:15 by mher              #+#    #+#             */
/*   Updated: 2022/01/01 16:37:08 by mher             ###   ########.fr       */
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
		if (info.type == 'c')
			if (check_char_format(&info) == -1)
				return (-1);
		if (ft_strchr("diupxX", info.type))
			if (check_nbr_format(&info) == -1)
				return (-1);
	}
	return (1);
}

int	check_char_format(t_info *info)
{
	if (info->alt == 1)
		return (-1);
	else if (info->zero == 1)
		return (-1);
	else if (info->showsign == 1)
		return (-1);
	else if (info->space == 1)
		return (-1);
	else if (info->prec != -1)
		return (-1);
	return (1);
}

int	check_nbr_format(t_info *info)
{
	if (ft_strchr("diup", info->type) && info->alt == 1)
		return (-1);
	if (info->zero == 1 && info->left == 1)
		return (-1);
	if ((info->showsign == 1 || info->space == 1) && info->alt == 1)
		return (-1);
	return (1);
}
