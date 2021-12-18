/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:44:32 by mher              #+#    #+#             */
/*   Updated: 2021/12/18 17:17:23 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_arg_info(const char **format, t_arg_info *arg_info)
{
	while (ft_strchr(FLAG, *(*format++)))
	{
		if (**format == '#')
			arg_info->alternate = 1;
		else if (**format == '0' && arg_info->minus == 0)
			arg_info->zero = 1;
		else if (**format == '-' && arg_info->zero == 0)
			arg_info->minus = 1;
		else if (**format == '+')
			arg_info->plus = 1;
		else if (**format == ' ')
			arg_info->space = 1;
		else
			return (FALSE);
	}
	if (ft_isdigit(**format))
		arg_info->width = ft_atoi(*format);
	*format += ft_numlen(arg_info->width);
	if (*(*format++) == '.' && arg_info->precision == -1)
		arg_info->precision = ft_atoi(*format);
	else
		return (FALSE);
	*format += ft_numlen(arg_info->precision);
	return (TRUE);
}
