/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2022/04/17 02:40:53 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *keep)
{
	char	*line;
	size_t	i;

	i = 0;
	while (keep[i] != '\n' && keep[i])
		++i;
	if (keep[i] == '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (0);
	i = 0;
	while (keep[i] != '\n' && keep[i])
	{
		line[i] = keep[i];
		++i;
	}
	if (keep[i] == '\n')
	{
		line[i] = '\n';
		++i;
	}
	line[i] = 0;
	return (line);
}

static char	*read_file(int fd, char *keep)
{
	char	*buff;
	char	*temp;
	ssize_t	read_size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		temp = keep;
		keep = ft_strjoin(temp, buff);
		free(temp);
		temp = 0;
		if (ft_strchr(keep, '\n') || !keep)
			break ;
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = 0;
	if (read_size < 0)
		return (0);
	return (keep);
}

char	*get_next_line(int fd)
{
	static char		*keep;
	char			*line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	keep = read_file(fd, keep);
	if (!keep)
		return (0);
	if (!*keep)
	{
		free(keep);
		keep = 0;
		return (0);
	}
	line = get_line(keep);
	if (!line)
		return (0);
	temp = keep;
	keep = ft_strdup(temp + ft_strlen(line));
	free(temp);
	temp = 0;
	if (!keep)
		return (0);
	return (line);
}
