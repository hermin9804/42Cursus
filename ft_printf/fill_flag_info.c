/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:44:32 by mher              #+#    #+#             */
/*   Updated: 2021/12/19 20:51:33 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_arg_info(const char *format, t_arg_info *arg_info)
{
	int	flag_len;
	int	width_len;

	flag_len = 0;
	width_len = 0;
	flag_len = fill_flag_info(&format, &arg_info);
	if (flag_len == FALSE)
		return (FALSE);
	format += flag_len;
	width_len = fill_width_info(&format, &arg_info);
	if (width_len == FALSE)
		return (FALSE);
	format += width_len;
	return (TRUE);
}


int	fill_flag_info(const char *format, t_arg_info *arg_info)
{
	int	i;
	
	i = 0;
	while (ft_strchr(FLAG, format[i]))
	{
		if (format[i++] == '#')
			arg_info->alternate = 1;
		else if (format[i++] == '0' && arg_info->minus == 0)
			arg_info->zero = 1;
		else if (format[i++] == '-' && arg_info->zero == 0)
			arg_info->minus = 1;
		else if (format[i++] == '+')
			arg_info->plus = 1;
		else if (format[i++] == ' ')
			arg_info->space = 1;
		else
			return (FALSE);
	}
	return (i);
}

int	fill_width_info(const char *format, t_arg_info *arg_info)
{
	int i;

	i = 0;
	arg_info->width = ft_atoi(&format[i]);
	i += ft_numlen(arg_info->width);
	if (format[i] == '.' && ('0' <= format[i + 1] && format[i + 1] <= '9'))
		arg_info->precision = ft_atoi(&format[++i]);
	i += ft_numlen(arg_info->precision);
	if (ft_strchr(TYPE, format[i]))
		arg_info->type = format[i++];
	else
		return (FALSE);
	return (i);
}
