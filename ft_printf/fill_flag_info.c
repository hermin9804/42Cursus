/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:44:32 by mher              #+#    #+#             */
/*   Updated: 2021/12/26 19:56:58 by mher             ###   ########.fr       */
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
		return (-1);
	*format += width_len;
	return (1);
}


int	fill_flags_info(const char *format, t_info *info)
{
	int	i;
	
	i = 0;
	while (ft_strchr("#0-+ ", format[i]))
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
	info->width = ft_atoi(&format[i]); //long max ?
	if (info->width != 0)
		i += ft_nbrlen_base(info->width, 10);
	if (format[i] == '.')
	{
		++i;
		info->prec = 0;//
		if (ft_isdigit(format[i]))
		{
			info->prec = ft_atoi(&format[i]);
			if (info->prec == -1) //long max ?
				return (-1);
			i += ft_nbrlen_base(info->prec, 10);
		}
	}
	if (ft_strchr("csdiupxX%", format[i]))
		info->type = format[i++];
	else
		return (-1);
	return (i);
}
