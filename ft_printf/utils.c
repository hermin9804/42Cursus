/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:15:58 by mher              #+#    #+#             */
/*   Updated: 2021/12/23 22:29:25 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int num)
{
	int len;

	len = 0;
	while (num)
	{
		++len;
		num /= 10;
	}
	return(len);
}

int	ft_putchar(char c, int *ret)
{
	*ret += 1;
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	str_len;

	str_len = 0;
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (ERROR);
		++str_len;
	}
	return (str_len);
}

int	char_type_padding(int len, t_info *info)
{
	int	pad_len;
	char	pad_char;

	pad_len = 0;
	pad_char = ' ';
	if (info->zero == 1)
		pad_char = '0';
	while (len++ < info->width)
	{
		if (write(1, &pad_char, 1) == -1)
			return (ERROR);
		++pad_len;
	}
	return (pad_len);
}
