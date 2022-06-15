/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:40:28 by mher              #+#    #+#             */
/*   Updated: 2022/06/02 15:58:53 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utiles.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	while (src[i] && i < (destsize - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (src_len);
}
