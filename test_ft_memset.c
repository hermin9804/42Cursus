/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:30:43 by mher              #+#    #+#             */
/*   Updated: 2021/11/27 18:51:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;
	long long 		cccc;

	new_b = (unsigned char *)b;
	cccc = (unsigned char)c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	cccc |= cccc << 32;
	while (len >= 32)
	{
		((long long *)new_b)[0] = cccc;
		((long long *)new_b)[1] = cccc;
		((long long *)new_b)[2] = cccc;
		((long long *)new_b)[3] = cccc;
		new_b += 32;
		len -= 32;
	}
	while (len >= 8)
	{
		((long long *)new_b)[0] = cccc;
		new_b += 8;
		len -= 8;
	}
	while (len--)
		*new_b++ = (unsigned char)cccc;
	return (b);
}

int main()
{
	char b1[] = "1234567123123kdjf;lkdjfl;akjdgl;kjsdgl;jsd;lfgj;lsjf8";
	char c1 = 'c';
	char b2[] = "1234567123123kdjf;lkdjfl;akjdgl;kjsdgl;jsd;lfgj;lsjf8";
	char c2 = 'c';
	printf("f : %s\n", (char *)ft_memset(b1, c1, -1));
	printf("f : %s\n", (char *)memset(b2, c2, -1));
	return (0);
}
