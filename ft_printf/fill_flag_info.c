/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:44:32 by mher              #+#    #+#             */
/*   Updated: 2021/12/19 23:09:44 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_arg_info(const char **format, t_arg_info *arg_info)
{
	int	flags_len;
	int	width_len;

	flags_len = 0;
	width_len = 0;
	flags_len = fill_flags_info(*format, arg_info);
	if (flags_len == -1)
		return (FALSE);
	*format += flags_len;
	width_len = fill_width_info(*format, arg_info);
	if (width_len == -1)
		return (FALSE);
	*format += width_len;
	return (TRUE);
}


int	fill_flags_info(const char *format, t_arg_info *arg_info)
{
	int	i;
	
	i = 0;
	while (ft_strchr(FLAG, format[i]))
	{
		if (format[i] == '#')
			arg_info->alternate = 1;
		else if (format[i] == '0' && arg_info->minus == 0)
			arg_info->zero = 1;
		else if (format[i] == '-' && arg_info->zero == 0)
			arg_info->minus = 1;
		else if (format[i] == '+')
			arg_info->plus = 1;
		else if (format[i] == ' ')
			arg_info->space = 1;
		else
			return (-1);
		++i;
	}
	return (i);
}

int	fill_width_info(const char *format, t_arg_info *arg_info)
{
	int i;

	i = 0;
	arg_info->width = ft_atoi(&format[i]);
	i += ft_numlen(arg_info->width);
	if (format[i] == '.' && ft_isdigit(format[i + 1]))
		arg_info->precision = ft_atoi(&format[++i]);
	i += ft_numlen(arg_info->precision);
	if (ft_strchr(TYPE, format[i]))
		arg_info->type = format[i++];
	else
		return (-1);
	return (i);
}
