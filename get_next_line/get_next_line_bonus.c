/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:31:47 by mher              #+#    #+#             */
/*   Updated: 2021/12/10 13:52:47 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*make_line(char *keep)
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

t_keep_lst	*find_fd(int fd, t_keep_lst *lst)
{
	t_keep_lst *temp;

	temp = lst->next;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_keep_lst *)malloc(sizeof(t_keep_lst));
	if (!temp)
		return (0);
	temp->fd = fd;
	temp->prev = lst;
	temp->next = lst->next; 
	if (lst->next)
		lst->next->prev = temp;
	lst->next = temp;
	temp->keep = 0;
	return (temp);
}

char	*free_curr_link_prev_next(t_keep_lst *lst)
{
	lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free(lst);
	lst = 0;
	return (0);
}

char	*get_line(t_keep_lst *lst)
{
	char	*line;
	char	*p;

	line = make_line(lst->keep);
	if (!line)
		return (0);
	p = lst->keep;
	lst->keep = ft_strdup(p + ft_strlen(line));
	free(p);
	p = 0;
	if (!(lst->keep))
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
//	char				*line;
	static t_keep_lst	keep_lst;
	t_keep_lst			*temp;
//	char				*p;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	temp = find_fd(fd, &keep_lst);
	temp->keep = read_file(fd, temp->keep);
	if (!(temp->keep))
		return (free_curr_link_prev_next(temp));
	if (*(temp->keep))
		return (get_line(temp));
	free(temp->keep);
	temp->keep = 0;
	return (free_curr_link_prev_next(temp));
}
/*
char	*get_next_line(int fd)
{
	char				*line;
	static t_keep_lst	keep_lst;
	t_keep_lst			*temp;
	char				*p;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	temp = find_fd(fd, &keep_lst);
	temp->keep = read_file(fd, temp->keep);
	if (!(temp->keep))
		return (free_curr_link_prev_next(temp));
	if (*(temp->keep))
	{
		line = get_line(temp->keep);
		if (!line)
			return (0);
		p = temp->keep;
		temp->keep = ft_strdup(p + ft_strlen(line));
		free(p);
		p = 0;
		if (!(temp->keep))
			return (0);
		return (line);
	}
	free(temp->keep);
	temp->keep = 0;
	return (free_curr_link_prev_next(temp));
}*/

/*char	*get_next_line(int fd)
{
	char				*line;
	static t_keep_lst	keep_lst;
	t_keep_lst			*temp;
	char				*p;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	temp = find_fd(fd, &keep_lst);
	temp->keep = read_file(fd, temp->keep);
	if (!(temp->keep))
	{
		temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		free(temp);
		temp = 0;
		return (0);
	}
	if (*(temp->keep))
	{
		line = get_line(temp->keep);
		if (!line)
			return (0);
		p = temp->keep;
		temp->keep = ft_strdup(p + ft_strlen(line));
		free(p);
		p = 0;
		if (!(temp->keep))
			return (0);
		return (line);
	}
	free(temp->keep);
	temp->keep = 0;
	//
	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	//
	free(temp);
	temp = 0;
	return (0);
}*/
