/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:53:08 by mher              #+#    #+#             */
/*   Updated: 2022/03/29 17:50:53 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	get_fd(const char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error_exit("map file open\n");
	return (fd);
}

void	get_map_chunks(t_game *game, const char *map_path)
{
	int	fd;
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
			error_exit("Map read fail.");
		free(sentence);
		sentence = temp;
	}
	game->map.chunks = ft_split(sentence, '\n');
	free(sentence);
	if (!game->map.chunks)
		error_exit("get chunks");
}

void	get_map_size(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map.chunks[i])
		i++;
	game->map.size.row = i;
	game->map.size.col = ft_strlen(game->map.chunks[0]);
}

//void	get_map_chunk(t_game *game, const char *map_path)
//{
//	int	fd;
//	char	*line;
//	t_list	*new;
//	//t_list	*cul;
//
//	fd = get_fd(map_path);
//	line = get_next_line(fd);
//	game->map.chunk = ft_lstnew(line);
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (!line)
//			break;
//		new = ft_lstnew(line);
//		if (!new)
//			error_exit("get map chynk\n");
//		ft_lstadd_back(&game->map.chunk, new);
//	}
//}
