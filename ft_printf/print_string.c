/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:49 by mher              #+#    #+#             */
/*   Updated: 2021/12/20 18:36:37 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, t_info *info)
{
	int	tmp;
	int	arg_len;
	
	tmp = 0;
	arg_len = 0;
	if (info->minus == 1)
	{
		tmp = ft_putstr(str);
		if (tmp == -1)
			return (ERROR);
		arg_len = tmp;
	}
	tmp = put_width(ft_strlen(str), info);
	if (tmp == -1)
		return (ERROR);
	arg_len += tmp;
	if (info->minus == 0)
	{
		tmp = ft_putstr(str);
		if (tmp == -1)
			return (ERROR);
		arg_len += tmp;
	}
	return (arg_len);
}
