/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:15:58 by mher              #+#    #+#             */
/*   Updated: 2021/12/26 17:25:49 by mher             ###   ########.fr       */
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
	unsigned int len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		++len;
		nbr /= base;
	}
	return(len);
}

int	run_function_order(t_info *info, int f1(t_info *), int f2(t_info *), int f3(t_info *))
{
	int ret;
	int tmp;

	tmp = 0;
	ret = 0;
	if (f1)
	{
		tmp = f1(info);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (f2)
	{
		tmp = f2(info);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (f3)
	{
		tmp = f3(info);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	return (ret);
}

int	padding_width(t_info *info)
{
	int	ret;
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
