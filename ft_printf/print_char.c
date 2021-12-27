/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:33:04 by mher              #+#    #+#             */
/*   Updated: 2021/12/27 18:02:29 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	info->c = c;
	info->width -= 1;
	if (info->left == 0)
		return (run_order(info, padding_width, putchar_info, 0));
	else
		return (run_order(info, putchar_info, padding_width, 0));
}

int	putchar_info(t_info *info)
{
	char	c;

	c = info->c;
	return (write(1, &c, 1));
}
