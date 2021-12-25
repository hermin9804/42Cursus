/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:44:32 by mher              #+#    #+#             */
/*   Updated: 2021/12/25 03:24:36 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_info(const char **format, t_info *info)
{
	int	flags_len;
	int	width_len;

	flags_len = 0;
	width_len = 0;
	flags_len = fill_flags_info(*format, info);
	*format += flags_len;
	width_len = fill_width_info(*format, info);
	if (width_len == -1)
		return (ERROR);
	*format += width_len;
	return (TRUE);
}


int	fill_flags_info(const char *format, t_info *info)
{
	int	i;
	
	i = 0;
	while (ft_strchr(FLAG, format[i]))
	{
		if (format[i] == '#')
			info->alt = 1;
		else if (format[i] == '0')
			info->zero = 1;
		else if (format[i] == '-')
			info->left = 1;
		else if (format[i] == '+')
			info->showsign = 1;
		else if (format[i] == ' ')
			info->space = 1;
		++i;
	}
	return (i);
}

int	fill_width_info(const char *format, t_info *info)
{
	int i;

	i = 0;
	info->width = ft_atoi(&format[i]);
	if (info->width != 0)
		i += ft_nbrlen_base(info->width, 10);
	if (format[i] == '.')
	{
		++i;
		if (ft_isdigit(format[i]))
		{
			info->prec = ft_atoi(&format[i]);
			if (info->prec == -1)
				return (ERROR);
			i += ft_nbrlen_base(info->prec, 10);
		}
	}
	if (ft_strchr(TYPE, format[i]))
	{
		info->type = format[i];
		++i;
	}
	else
		return (ERROR);
	return (i);
}
