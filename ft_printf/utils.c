/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:15:58 by mher              #+#    #+#             */
/*   Updated: 2021/12/24 03:36:29 by mher             ###   ########.fr       */
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

int	ft_putnbr(long long n)
{
	unsigned long long	ret;
	int			tmp;

	ret = 0;
	tmp = 0;
	//if (n == -2147483648) long long max???
	//	return (write(1, "2147483648", 10));
	if (n < 0)
		n *= -1;
	if (n > 9)
		tmp = ft_putnbr(n / 10);
	if (tmp == -1)
		return (-1);
	ret += tmp;
	tmp = write(1, &"0123456789"[n % 10], 1);;
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	return (ret);
}
