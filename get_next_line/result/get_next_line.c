/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2021/12/06 21:31:06 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_temp(char *temp)
{
	char 	*ret;
	size_t	i;

	i = 0;
	while(temp[i] != '\n' && temp[i])
		++i;
	ret = (char *)malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (0);
	i = 0;
	while(temp[i] != '\n' && temp[i])
	{
		ret[i] = temp[i];
		++i;
	}
	if (temp[i] == '\n')
	{
		ret[i] = '\n';
		++i;
	}
	ret[i] = 0;
	return (ret);
}


char	*get_next_line(int fd)
{
	static char		*temp;
	char			*line;
	char			buff[BUFF_SIZE + 1];
	int				read_size;
	int				i;

	if (fd < 0)
		return (0);
	read_size = read(fd, buff, BUFF_SIZE);
	while (0 < read_size)
	{
		i = 0;
		buff[read_size] = '\0';
		while (buff[i] && buff[i] != '\n')
			++i;
		temp = ft_strjoin(temp, buff);
		if (ft_strlen(buff) != BUFF_SIZE)
			break ;
		read_size = read(fd, buff, BUFF_SIZE);
	}
	line = get_line_temp(temp);
	temp += ft_strlen(line);
	return (line);
}

int	main()
{
	int fd;
	char *file = "test.txt";

	fd = open(file, O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
