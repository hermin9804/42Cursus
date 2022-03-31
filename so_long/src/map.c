/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:53:08 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 11:52:13 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	get_fd(const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_exit("failed file open.");
	return (fd);
}

void	get_map_chunks(t_game *game, const char *map_path)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*sentence;

	fd = get_fd(map_path);
	sentence = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(sentence, line);
		free(line);
		if (!temp)
			error_exit("failed Map read.");
		free(sentence);
		sentence = temp;
	}
	game->map.chunks = ft_split(sentence, '\n');
	free(sentence);
	if (!game->map.chunks || !game->map.chunks[0])
		error_exit("failed Map read.");
}

void	get_map_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->chunks[i])
		i++;
	map->size.row = i;
	map->size.col = ft_strlen(map->chunks[0]);
}
