/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:47:18 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 17:42:24 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_file_path)
{
	init_map(game, *map_file_path);
	init_player(game);
	init_mlx(game);
	init_win(game);
	init_img(game);
}

void	solong(char *ag, int *row, int *col)
{
	char	*tmp;
	char	**map;
	
	tmp = read_map(ag, row);
	map = ft_split(tmp, '\n');
	*col = ft_strlen(map[0]);
}

void	init_map(t_game *gamep, char *map_file_path)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_exit("map file open\n");
	while (1)
	{
		*row += 1;	
		tmp = total_map;
		line = get_next_line(fd);
		if (!line)
			break;
		total_map = ft_strjoin(tmp, line);
		if (total_map == 0)
			return (0);
	}
	return (total_map);
}

	
char	*read_map(t_game)
{
	int		fd;
	char	*line;
	char	*total_map;
	char	*tmp;

	total_map = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		*row += 1;	
		tmp = total_map;
		line = get_next_line(fd);
		if (!line)
			break;
		total_map = ft_strjoin(tmp, line);
		if (total_map == 0)
			return (0);
	}
	return (total_map);
}

void	init_img(game)
{
	game.imgs.snow_img = get_img(game, "../asset/snow_img.xpm");
	game.imgs.wall_img = get_img(game, "../asset/wall_img.xpm");
	game.imgs.sign_img = get_img(game, "../asset/sign_img.xpm");
	game.imgs.home_img = get_img(game, "../asset/heom_img.xpm");
	game.imgs.dino_img = get_img(game, "../asset/dino_img.xpm");
}

void	init_mlx(t_game *game)
{
	game.mlx = mlx_init();
	//todo??: error handling
}

void	init_win(t_game *game)
{
	game.win = mlx_new_window(game.mlx, game.map.col_size * PX, 
			game.map.row_size * PX, "so_long");
	//todo??: error handling
}
