/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:20 by mher              #+#    #+#             */
/*   Updated: 2021/12/25 03:15:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(unsigned long long nbr, t_info *info)
{
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr *= -1;
	}
	info->nbr = nbr;
	info->nbr_len = ft_nbrlen_base(nbr, info->nbr_base);
	if (info->prec > 0)
		info->prec -= info->nbr_len;
	else
		info->prec = 0;
	info->width -= info->nbr_len + info->prec;
	if (info->nbr_sign == -1 || info->space == 1 || info->showsign == 1)
		info->width -= 1;
	if (info->type == 'p')
		info->width -= 2;
	if (info->left == 0)
		return (set_order_right(info));
	if (info->left == 1)
		return (set_order_left(info));
	return (ERROR);
}

int	set_order_right(t_info *info)
{
	if (info->width == 0 && info->prec == 0 && info->zero == 0)
		return (run_function_order(info, 0, put_sign_alt, padding_prec_putnbr));
	if (info->width == 0 && info->prec == 0 && info->zero == 1)
		return (run_function_order(info, 0, put_sign_alt, padding_prec_putnbr));
	if (info->width == 0 && info->prec != 0 && info->zero == 0)
		return (run_function_order(info, 0, put_sign_alt, padding_prec_putnbr));
	if (info->width == 0 && info->prec != 0 && info->zero == 1)
		return (run_function_order(info, 0, put_sign_alt, padding_prec_putnbr));
	if (info->width != 0 && info->prec == 0 && info->zero == 0)
		return (run_function_order(info, padding_width, put_sign_alt, padding_prec_putnbr));
	if (info->width != 0 && info->prec == 0 && info->zero == 1) 
		return (run_function_order(info, put_sign_alt, padding_width, padding_prec_putnbr));
	if (info->width != 0 && info->prec != 0 && info->zero == 0) 
		return (run_function_order(info, padding_width, put_sign_alt, padding_prec_putnbr));
	if (info->width != 0 && info->prec != 0 && info->zero == 1)
		return (run_function_order(info, padding_width, put_sign_alt, padding_prec_putnbr));
	return (ERROR);
}

int	set_order_left(t_info *info)
{
	if (info->width == 0 && info->prec == 0 && info->left == 1)
		return (run_function_order(info, padding_width, put_sign_alt, padding_prec_putnbr));
	if (info->width == 0 && info->prec != 0 && info->left == 1)
		return (run_function_order(info, padding_width, put_sign_alt, padding_prec_putnbr));
	if (info->width != 0 && info->prec == 0 && info->left == 1)
		return (run_function_order(info, put_sign_alt, padding_prec_putnbr, padding_width));
	if (info->width != 0 && info->prec != 0 && info->left == 1)
		return (run_function_order(info, put_sign_alt, padding_prec_putnbr, padding_width));
	return (ERROR);
}

int	run_function_order(t_info *info, int f1(t_info *), int f2(t_info *), int f3(t_info *))
{
	int ret;
	int tmp;

	tmp = 0;
	ret = 0;
	if (f1)
		tmp = f1(info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	if (f2)
		tmp = f2(info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	if (f3)
		tmp = f3(info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
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
			return (ERROR);
		++ret;
	}
	return (ret);
}

int	padding_prec_putnbr(t_info *info)
{
	int	ret;
	int	tmp;

	ret = 0;
	tmp = 0;
	while (0 < info->prec--)
	{
		if (write(1, "0", 1) == -1)
			return (ERROR);
		ret++;
	}
	tmp = ft_putnbr(info->nbr, info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
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
	else if (info->alt == 1 && info->type == 'x')
		return (write(1, "0x", 2));
	else if (info->alt == 1 && info->type == 'X')
		return (write(1, "0X", 2));
	else if (info->type == 'p')
		return (write(1, "0x", 2));
	else
		return (0);
}
