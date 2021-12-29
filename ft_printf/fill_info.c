/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flag_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:44:32 by mher              #+#    #+#             */
/*   Updated: 2021/12/30 01:07:12 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_info(const char **format, t_info *info)
{
	*format += fill_flags_info(*format, info);
	*format += fill_width_prec_info(*format, info);
	*format += fill_type_info(*format, info);
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

int	fill_width_prec_info(const char *format, t_info *info)
{
	int	i;

	i = 0;
	info->width = ft_atoi(&format[i]);
	if (info->width != 0)
		i += ft_nbrlen_base(info->width, 10);
	if (format[i] == '.')
		info->prec = ft_atoi(&format[++i]);
	if (info->prec > 0)
		i += ft_nbrlen_base(info->prec, 10);
	return (i);
}

int	fill_type_info(const char *format, t_info *info)
{
	if (!ft_strchr("csdiupxX%", *format))
		return (0);
	info->type = *format;
	return (1);
}
