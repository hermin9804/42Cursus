/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:15:58 by mher              #+#    #+#             */
/*   Updated: 2021/12/27 17:44:40 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *ret)
{
	*ret += 1;
	return (write(1, &c, 1));
}

int	ft_nbrlen_base(unsigned long long nbr, int base)
{
	unsigned int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		++len;
		nbr /= base;
	}
	return (len);
}

int	run_function_order(t_info *info, int f1(t_info *),
	int f2(t_info *), int f3(t_info *))
{
	int	ret1;
	int	ret2;
	int	ret3;

	ret1 = 0;
	ret2 = 0;
	ret3 = 0;
	if (f1)
		ret1 = f1(info);
	if (ret1 == -1)
		return (-1);
	if (f2)
		ret2 = f2(info);
	if (ret2 == -1)
		return (-1);
	if (f3)
		ret3 = f3(info);
	if (ret3 == -1)
		return (-1);
	return (ret1 + ret2 + ret3);
}

int	padding_width(t_info *info)
{
	int		ret;
	char	pad_char;

	ret = 0;
	pad_char = ' ';
	if (info->zero == 1 && info->prec == 0)
		pad_char = '0';
	while (0 < info->width--)
	{
		if (write(1, &pad_char, 1) == -1)
			return (-1);
		++ret;
	}
	return (ret);
}

int	put_sign_alt(t_info *info)
{
	if (info->nbr_sign == -1)
		return (write(1, "-", 1));
	else if (info->showsign == 1)
		return (write(1, "+", 1));
	else if (info->space == 1)
		return (write(1, " ", 1));
	else if (info->alt == 1 && info->type == 'x' && info->nbr != 0)
		return (write(1, "0x", 2));
	else if (info->alt == 1 && info->type == 'X' && info->nbr != 0)
		return (write(1, "0X", 2));
	else if (info->type == 'p')
		return (write(1, "0x", 2));
	else
		return (0);
}
