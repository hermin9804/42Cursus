/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:09:49 by mher              #+#    #+#             */
/*   Updated: 2021/12/26 17:59:46 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, t_info *info)
{
	int	str_len;

	str_len = 0;
	info->str = str;
	if (str != NULL)
		str_len = ft_strlen(str);
	if (info->prec > str_len || info->prec == -1)
		info->prec = str_len;
	info->width -= str_len;
	if (info->left == 0)
		return (run_function_order(info, padding_width, put_sign_alt, print_prec_str));
	else if (info->left == 1)
		return (run_function_order(info, put_sign_alt, print_prec_str, padding_width));
	return (-1);
}

int	print_prec_str(t_info *info)
{
	int	ret;
	char	*str;

	ret = 0;
	str = info->str;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str && 0 < info->prec--)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		++str;
		++ret;
	}
	return (ret);
}
