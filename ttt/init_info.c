/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:16:34 by mher              #+#    #+#             */
/*   Updated: 2022/01/01 01:22:50 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->type = 0;
	info->width = 0;
	info->prec = -1;
	info->alt = 0;
	info->zero = 0;
	info->left = 0;
	info->showsign = 0;
	info->space = 0;
	info->nbr_sign = 0;
	info->nbr_len = 0;
	info->nbr_base = 10;
	info->c = 0;
	info->str = 0;
	info->nbr = 0;
}
