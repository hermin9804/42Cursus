/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:49 by mher              #+#    #+#             */
/*   Updated: 2021/12/25 02:38:04 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, t_info *info)
{
	int	tmp;
	int	arg_len;
	
	tmp = 0;
	arg_len = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	if (info->left == 1)
	{
		tmp = ft_putstr(str);
		if (tmp == -1)
			return (ERROR);
		arg_len = tmp;
	}
	tmp = char_type_padding(ft_strlen(str), info);
	if (tmp == -1)
		return (ERROR);
	arg_len += tmp;
	if (info->left == 0)
	{
		tmp = ft_putstr(str);
		if (tmp == -1)
			return (ERROR);
		arg_len += tmp;
	}
	return (arg_len);
}
