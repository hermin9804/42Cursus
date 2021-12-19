/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:33:04 by mher              #+#    #+#             */
/*   Updated: 2021/12/20 01:26:14 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_arg_info arg_info)
{
	int	arg_len;
	
	arg_len = 0;
	if (arg_info.minus == 1)
		arg_len += write(1, &c, 1);
	arg_len += put_width(1, arg_info);
	if (arg_info.minus == 0)
		arg_len += write(1, &c, 1);
	return (arg_len);
}

int	put_width(int len, t_arg_info arg_info)
{
	int	ret;
	char	width_char;

	ret = 0;
	if (arg_info.zero == 1)
		width_char = '0';
	else
		width_char = ' ';
	while (len++ < arg_info.width)
	{
		if (write(1, &width_char, 1) == -1)
			return (-1);
		++ret;
	}
	return (ret);
}
