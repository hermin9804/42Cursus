/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:17:22 by mher              #+#    #+#             */
/*   Updated: 2021/11/19 13:55:34 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
	{
		++i;
		++dst;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst = *src;
		++dst;
		++src;
		++i;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}
