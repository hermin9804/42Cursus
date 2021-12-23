/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:20 by mher              #+#    #+#             */
/*   Updated: 2021/12/24 02:16:26 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	print_nbr(int nbr, t_info *info)
{
	int	tmp1 = 0;
	int	tmp2 = 0;
	int	tmp3 = 0;

	if (nbr < 0)
		info->nbr_sign = -1;
	if (info->left == 1)
	{
		if (info->prec != -1)
		{
			tmp1 = put_prec_width(ft_numlen(nbr), info->prec, info);
			if (tmp1 == -1)
				return (ERROR);
			tmp2 = ft_putnbr(nbr);
			if (tmp2 == -1)
				return (ERROR);
			tmp3 = put_width_nbr_flags(0, info->prec, info);
			if (tmp3 == -1)
				return (ERROR);
		}
		if (info->prec == -1)
		{
			if (info->nbr_sign == -1)
			{
				tmp1 = write(1, "-", 1);
				if (tmp1 == -1)
					return (ERROR);
			}
			tmp2 = ft_putnbr(nbr);
			if (tmp2 == -1)
				return (ERROR);
			tmp3 = put_width_nbr_flags(ft_numlen(nbr), info->width, info);
			if (tmp3 == -1)
				return (ERROR);
		}
	}
	else
	{
		if (info->prec != -1)
		{
			tmp1 = put_width_nbr_flags(info->prec, info->width, info);
			if (tmp1 == -1)
				return (ERROR);
			tmp2 = put_prec_width(ft_numlen(nbr), info->prec, info);
			if (tmp2 == -1)
				return (ERROR);
			tmp3 = ft_putnbr(nbr);
			if (tmp3 == -1)
				return (ERROR);
		}
		if (info->prec == -1)
		{
			if (info->nbr_sign == -1 && info->zero == 0 && info->width == 0)
			{
				tmp1 = write(1, "-", 1);
				if (tmp1 == -1)
					return (ERROR);
			}
			tmp2 = put_width_nbr_flags(ft_numlen(nbr), info->width, info);
			if (tmp2 == -1)
				return (ERROR);
			if (info->nbr_sign == -1 && info->zero == 0 && info->width != 0)
			{
				tmp1 = write(1, "-", 1);
				if (tmp1 == -1)
					return (ERROR);
			}
			tmp3 = ft_putnbr(nbr);
			if (tmp3 == -1)
				return (ERROR);
		}
	}
	return (tmp1 + tmp2 + tmp3);
}

int	put_width_nbr_flags(int start, int end, t_info *info)
{
	int		ret;
	char		width_char;

	ret = 0;
	width_char = ' ';
	if (info->zero == 1 && info->prec == -1)
		width_char = '0';
	if (info->nbr_sign == -1 && info->prec == -1 && info->zero == 1)
	{
		ret += 1;
		if (write(1, "-", 1) == -1)
			return (ERROR);
	}
	while (start++ < end + info->nbr_sign)
	{
		if (write(1, &width_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	if (info->nbr_sign == -1 && info->prec != -1 && info->left == 0)
	{
		ret += 1;
		if (write(1, "-", 1) == -1)
			return (ERROR);
	}
	return (ret);
}

int	put_prec_width(int start, int end, t_info *info)
{
	int		ret;
	char	width_char;

	ret = 0;
	width_char = '0';
	if (info->nbr_sign == -1 && info->width != 0 && info->prec != -1 && info->left == 1)
	{
		ret += 1;
		if (write(1, "-", 1) == -1)
			return (ERROR);
	}
	while (start++ < end)
	{
		if (write(1, &width_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	return (ret);
}*/

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

int	print_nbr(long long nbr, t_info *info)
{
	info->nbr = nbr;
	if (nbr < 0)
		info->nbr_sign = -1;
	info->nbr_len = ft_numlen(nbr);
	if (info->prec > 0)
		info->prec -= info->nbr_len;
	else
		info->prec = 0;
	if (info->width > 0)
		info->width -= info->nbr_len + info->prec + (info->nbr_sign * -1);
	
	
	if (info->left == 0)
		return (set_order_zero(info));
	if (info->left == 1)
		return (set_order_left(info));
	return (ERROR);
}

int	set_order_zero(t_info *info)
{
	if (info->width == 0 && info->prec == 0 && info->zero == 0)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec == 0 && info->zero == 1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec != 0 && info->zero == 0)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec != 0 && info->zero == 1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width != 0 && info->prec == 0 && info->zero == 0)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width != 0 && info->prec == 0 && info->zero == 1) 
		return (run_function_order(info, put_sign, padding_width, padding_prec_putnbr));
	if (info->width != 0 && info->prec != 0 && info->zero == 0) 
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width != 0 && info->prec != 0 && info->zero == 1)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	return (ERROR);
}

int	set_order_left(t_info *info)
{
	if (info->width == 0 && info->prec == 0 && info->left == 0)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec == 0 && info->left == 1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec != 0 && info->left == 0)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec != 0 && info->left == 1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width != 0 && info->prec == 0 && info->left == 0)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width != 0 && info->prec == 0 && info->left == 1) //
		return (run_function_order(info, put_sign, padding_prec_putnbr, padding_width));
	if (info->width != 0 && info->prec != 0 && info->left == 0) 
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width != 0 && info->prec != 0 && info->left == 1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, padding_width));
	return (ERROR);
}

int	run_function_order(t_info *info, int f1(t_info *), int f2(t_info *), int f3(t_info *))
{
	int ret;
	int tmp;

	tmp = 0;
	ret = 0;
	ret = info->width + info->nbr_len + info->prec + (info->nbr_sign * -1);
	if (f1)
		tmp = f1(info);
	if (tmp == -1)
		return (ERROR);
	if (f2)
		tmp = f2(info);
	if (tmp == -1)
		return (ERROR);
	if (f3)
		tmp = f3(info);
	if (tmp == -1)
		return (ERROR);
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
	}
	tmp = ft_putnbr(info->nbr);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	return (ret);
}

int	put_sign(t_info *info)
{
	if (info->space == 1)
		return (write(1, " ", 1));
	else if (info->nbr_sign == -1)
		return (write(1, "-", 1));
	else if (info->showsign == 1)
		return (write(1, "+", 1));
	else
		return (0);
}
