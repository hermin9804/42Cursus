/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2021/12/09 13:23:35 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	tmp = ret;
	while (len--)
	{
		*tmp = *s1;
		++tmp;
		++s1;
	}
	*tmp = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, s2_len + 1);
	return (ret);
}

char	*get_line(char *keep)
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

char	*read_file(int fd, char *keep)
{
	char	*buff;
	char	*temp;
	ssize_t	read_size;

	if (fd < 0)
		return (0);
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
	return (keep);
}

char	*get_next_line(int fd)
{
	static char		*keep;
	char			*line;
	char			*temp;

	keep = read_file(fd, keep);
	if (!keep)
		return (0);
	if (*keep)
	{
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
	free(keep);
	keep = 0;
	return (0);
}
