/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:59:03 by mher              #+#    #+#             */
/*   Updated: 2021/12/24 03:41:04 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	
	printf(": %d", ft_printf("%d", 432));
	printf("\n");
	printf(": %d", printf("%d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%10d", 432));
	printf("\n");
	printf(": %d", printf("%10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%-10d", 432));
	printf("\n");
	printf(": %d", printf("%-10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%-10d", 432));
	printf("\n");
	printf(": %d", printf("%-10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%10.5d", 432));
	printf("\n");
	printf(": %d", printf("%10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%-10.5d", 432));
	printf("\n");
	printf(": %d", printf("%-10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%.5d", 432));
	printf("\n");
	printf(": %d", printf("%.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%0d", 432));
	printf("\n");
	printf(": %d", printf("%0d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%010d", 432));
	printf("\n");
	printf(": %d", printf("%010d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%010.5d", 432));//
	printf("\n");
	printf(": %d", printf("%010.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%0.5d", 432));
	printf("\n");
	printf(": %d", printf("%0.5d", 432));
	printf("\n");
	printf("\n");


	printf("--------------------");

	printf("\n");
	printf("\n");

	printf(": %d", ft_printf("%+d", 432));
	printf("\n");
	printf(": %d", printf("%+d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+10d", 432));
	printf("\n");
	printf(": %d", printf("%+10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+-10d", 432));
	printf("\n");
	printf(": %d", printf("%+-10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+-10d", 432));
	printf("\n");
	printf(": %d", printf("%+-10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+10.5d", 432));
	printf("\n");
	printf(": %d", printf("%+10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+-10.5d", 432));
	printf("\n");
	printf(": %d", printf("%+-10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+.5d", 432));
	printf("\n");
	printf(": %d", printf("%+.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+0d", 432));
	printf("\n");
	printf(": %d", printf("%+0d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+010d", 432));
	printf("\n");
	printf(": %d", printf("%+010d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+010.5d", 432));//
	printf("\n");
	printf(": %d", printf("%0+10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%+0.5d", 432));
	printf("\n");
	printf(": %d", printf("%+0.5d", 432));
	printf("\n");
	printf("\n");
	
	printf("\n");
	printf("--------------------");
	printf("\n");


	printf(": %d", ft_printf("%d", -432));
	printf("\n");
	printf(": %d", printf("%d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%10d", -432));
	printf("\n");
	printf(": %d", printf("%10d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%-10d", -432));
	printf("\n");
	printf(": %d", printf("%-10d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%-10d", -432));
	printf("\n");
	printf(": %d", printf("%-10d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%10.5d", -432));//
	printf("\n");
	printf(": %d", printf("%10.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%-10.5d", -432));
	printf("\n");
	printf(": %d", printf("%-10.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%.5d", -432));
	printf("\n");
	printf(": %d", printf("%.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%0d", -432));
	printf("\n");
	printf(": %d", printf("%0d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%010d", -432));
	printf("\n");
	printf(": %d", printf("%010d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%010.5d", -432));//
	printf("\n");
	printf(": %d", printf("%010.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("%0.5d", -432));
	printf("\n");
	printf(": %d", printf("%0.5d", -432));



	printf("\n");
	printf("--------------------");
	printf("\n");



	printf(": %d", ft_printf("% d", 432));
	printf("\n");
	printf(": %d", printf("% d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 10d", 432));
	printf("\n");
	printf(": %d", printf("% 10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% -10d", 432));
	printf("\n");
	printf(": %d", printf("% -10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% -10d", 432));
	printf("\n");
	printf(": %d", printf("% -10d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 10.5d", 432));
	printf("\n");
	printf(": %d", printf("% 10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% -10.5d", 432));
	printf("\n");
	printf(": %d", printf("% -10.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% .5d", 432));
	printf("\n");
	printf(": %d", printf("% .5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 0d", 432));
	printf("\n");
	printf(": %d", printf("% 0d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 010d", 432));
	printf("\n");
	printf(": %d", printf("% 010d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 010.5d", 432));//
	printf("\n");
	printf(": %d", printf("% 010.5d", 432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 0.5d", 432));
	printf("\n");
	printf(": %d", printf("% 0.5d", 432));
	printf("\n");
	printf("\n");

	printf("\n");
	printf("--------------------");
	printf("\n");



	printf(": %d", ft_printf("% d", -432));
	printf("\n");
	printf(": %d", printf("% d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 10d", -432));
	printf("\n");
	printf(": %d", printf("% 10d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% -10d", -432));
	printf("\n");
	printf(": %d", printf("% -10d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% -10d", -432));
	printf("\n");
	printf(": %d", printf("% -10d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 10.5d", -432));
	printf("\n");
	printf(": %d", printf("% 10.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% -10.5d", -432));
	printf("\n");
	printf(": %d", printf("% -10.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% .5d", -432));
	printf("\n");
	printf(": %d", printf("% .5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 0d", -432));
	printf("\n");
	printf(": %d", printf("% 0d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 010d", -432));
	printf("\n");
	printf(": %d", printf("% 010d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 010.5d", -432));//
	printf("\n");
	printf(": %d", printf("% 010.5d", -432));
	printf("\n");
	printf("\n");
	printf(": %d", ft_printf("% 0.5d", -432));
	printf("\n");
	printf(": %d", printf("% 0.5d", -432));
	printf("\n");
	printf("\n");

	//printf(" %d\n", ft_printf("%4d", -10));
	//printf(" %d\n", printf("%4d", -10));

	return (0);
}
