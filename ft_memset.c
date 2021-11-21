/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:30:43 by mher              #+#    #+#             */
/*   Updated: 2021/11/21 14:39:07 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	unsigned char	new_c;
	size_t			i;

	new_b = b;
	new_c = c;
	i = 0;
	while (i++ < len)
		*new_b++ = new_c;
	return (b);
}
