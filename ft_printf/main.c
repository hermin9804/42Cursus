/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:59:03 by mher              #+#    #+#             */
/*   Updated: 2021/12/24 20:27:31 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("%c", '0');
	printf("\n");
	printf("%c", '0');
	printf("\n");
	printf("\n");

	ft_printf(" %c ", '0');
	printf("\n");
	printf(" %c ", '0');
	printf("\n");
	printf("\n");

	ft_printf(" %c", '0' - 256);
	printf("\n");
	printf(" %c", '0' - 256);
	printf("\n");
	printf("\n");

	printf("%d", ft_printf("[%c ]", '0' + 256));
	printf("\n");
	printf("%d", printf("[%c ]", '0' + 256));
	printf("\n");
	printf("\n");

	printf("%d", ft_printf("[ %c %c %c ]", '0', 0, '1'));
	printf("\n");
	printf("%d", printf("[ %c %c %c ]", '0', 0, '1'));
	printf("\n");
	printf("\n");

	ft_printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\n");
	printf(" %c %c %c ", ' ', ' ', ' ');
	printf("\n");
	printf("\n");

	ft_printf(" %c %c %c ", '1', '2', '3');
	printf("\n");
	printf(" %c %c %c ", '1', '2', '3');
	printf("\n");
	printf("\n");

	ft_printf(" %c %c %c ", '2', '1', 0);
	printf("\n");
	printf(" %c %c %c ", '2', '1', 0);
	printf("\n");
	printf("\n");

	ft_printf(" %c %c %c ", 0, '1', '2');
	printf("\n");
	printf(" %c %c %c ", 0, '1', '2');
	printf("\n");
	printf("\n");
	return (0);
}
