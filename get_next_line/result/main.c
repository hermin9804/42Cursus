/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2021/12/07 19:54:47 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int fd;
	char *file = "test.txt";
	char *temp;


	fd = open(file, O_RDONLY);

	temp = get_next_line(fd);
	printf("%s", temp);
	free(temp);

	temp = get_next_line(fd);
	printf("%s", temp);
	free(temp);

	temp = get_next_line(fd);
	printf("%s", temp);
	free(temp);

	close(fd);
	return (0);
}
