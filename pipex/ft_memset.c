/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:30:41 by mher              #+#    #+#             */
/*   Updated: 2022/05/06 18:23:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	unsigned char	new_c;

	new_b = (unsigned char *)b;
	new_c = (unsigned char)c;
	while (len--)
		*new_b++ = new_c;
	return (b);
}
