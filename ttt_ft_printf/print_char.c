/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:33:04 by mher              #+#    #+#             */
/*   Updated: 2021/12/23 19:05:26 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	int	tmp;
	int	arg_len;
	
	tmp = 0;
	arg_len = 0;
	if (info->left == 1)
	{
		tmp = write(1, &c, 1);
		if (tmp == -1)
			return (ERROR);
		arg_len = tmp;
	}
	tmp = char_type_padding(1, info);
	if (tmp == -1)
		return (ERROR);
	arg_len += tmp;
	if (info->left == 0)
	{
		tmp = write(1, &c, 1);
		if (tmp == -1)
			return (ERROR);
		arg_len += tmp;
	}
	return (arg_len);
}
