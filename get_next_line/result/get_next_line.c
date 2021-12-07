/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2021/12/07 21:22:14 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_temp(char *temp)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		++i;
	if (temp[i] == '\n')
		++i;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	i = 0;
	while (temp[i] != '\n' && temp[i])
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
	char			buff[BUFFER_SIZE + 1];
	int				read_size;
	char *p;

	if (fd < 0)
		return (0);
	read_size = read(fd, buff, BUFFER_SIZE);
	while (0 < read_size)
	{
		buff[read_size] = '\0';
		p = temp;
		temp = ft_strjoin(p, buff);
		free(p);
		if (ft_strlen(buff) != BUFFER_SIZE)
			break ;
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	if (!temp)
		return (0);
	if (*temp)
	{
		line = get_line_temp(temp);
		p = temp;
		temp = ft_strdup(p + ft_strlen(line));
		free(p);
		return (line);
	}
	free(temp);
	return (0);
}
