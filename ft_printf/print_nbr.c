/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:20 by mher              #+#    #+#             */
/*   Updated: 2021/12/23 23:28:32 by mher             ###   ########.fr       */
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
	if (info->left == 0)
		return (set_order_right(info));
	//if (info->left == 1)
	//	return (set_order_left(info));
	return (ERROR);
}

int	set_order_right(t_info *info)
{
	if (info->width == 0 && info->prec == -1 && info->nbr_sign == 0)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec == -1 && info->nbr_sign == -1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec != -1 && info->nbr_sign == 0)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width == 0 && info->prec != -1 && info->nbr_sign == -1)
		return (run_function_order(info, put_sign, padding_prec_putnbr, 0));
	if (info->width > 0 && info->prec == -1 && info->nbr_sign == 0)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width > 0 && info->prec == -1 && info->nbr_sign == -1)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width > 0 && info->prec != -1 && info->nbr_sign == 0)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	if (info->width > 0 && info->prec != -1 && info->nbr_sign == -1)
		return (run_function_order(info, padding_width, put_sign, padding_prec_putnbr));
	return (ERROR);
}
/*
int	set_oder_left(t_info *info)
}
	if (info->width == 0 && info->prec == -1 && info->nbr_sign == 0)
		return (print_order(info, padding_width, padding_prec, put_sign));
	if (info->width == 0 && info->prec == -1 && info->nbr_sign == -1)
		return (print_order(info, f1, f2, f3));
	if (info->width == 0 && info->prec != -1 && info->nbr_sign == 0)
		return (print_order(info, f1, f2, f3));
	if (info->width == 0 && info->prec != -1 && info->nbr_sign == -1)
		return (print_order(info, f1, f2, f3));
	if (info->width == 1 && info->prec == -1 && info->nbr_sign == 0)
		return (print_order(info, f1, f2, f3));
	if (info->width == 1 && info->prec == -1 && info->nbr_sign == -1)
		return (print_order(info, f1, f2, f3));
	if (info->width == 1 && info->prec != -1 && info->nbr_sign == 0)
		return (print_order(info, f1, f2, f3));
	if (info->width == 1 && info->prec != -1 && info->nbr_sign == -1)
		return (print_order(info, f1, f2, f3));
}
*/

int	run_function_order(t_info *info, int f1(int, t_info *), int f2(int, t_info *), int f3(int, t_info *))
{
	int ret;
	int tmp;

	tmp = 0;
	ret = info->width;
	if (info->width < ft_numlen(info->nbr))
		ret = numlen + (info->nbr_sign * -1);
	if (f1)
		tmp = f1(ret, info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	if (f2)
		tmp = f2(ret, info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	if (f3)
		tmp = f3(ret, info);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	return (ret);
}

int	padding_width(int start, t_info *info)
{
	int	ret;
	int	end;
	char	pad_char;

	ret = 0;
	end = info->width - ft_numlen(info->nbr);
	pad_char = ' ';
	if (info->zero == 1 && info->prec == -1)
		pad_char = '0';
	while (start++ < end)
	{
		if (write(1, &pad_char, 1) == -1)
			return (ERROR);
		++ret;
	}
	return (ret);
}

int	padding_prec_putnbr(int start, t_info *info)
{
	int	ret;
	int	tmp;
	int	end;

	ret = 0;
	tmp = 0;
	end = info->prec - ft_numlen(info->nbr);
	while (start++ < end && end > 0)
	{
		if (write(1, "0", 1) == -1)
			return (ERROR);
		++ret;
	}
	tmp = ft_putnbr(info->nbr);
	if (tmp == -1)
		return (ERROR);
	ret += tmp;
	return (ret);
}

int	put_sign(int start, t_info *info)
{
	if (info->space == 1)
		return (write(1, " ", 1));
	else if (info->nbr_sign == -1)
		return (write(1, "-", 1));
	else if (info->showsign == 1)
		return (write(1, "+", 1));
	else if (start < 0)
		return (ERROR);
	else
		return (0);
}
