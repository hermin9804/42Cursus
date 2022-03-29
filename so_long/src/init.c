/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:47:18 by mher              #+#    #+#             */
/*   Updated: 2022/03/30 02:33:50 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_path)
{
	init_map(game, map_path);
	init_player(game);
	init_mlx(game);
	init_win(game);
	init_img(game);
	game->doorock = 0;
}

void	init_map(t_game *game, const char *map_path)
{
	get_map_chunks(game, map_path);
	get_map_size(game);
	//check_map();
}

void	init_img(t_game *game)
{
	game->imgs.snow = get_img(game, "./asset/snow.xpm");
	game->imgs.wall = get_img(game, "./asset/wall.xpm");
	game->imgs.sign = get_img(game, "./asset/sign.xpm");
	game->imgs.home = get_img(game, "./asset/home.xpm");
	game->imgs.dino = get_img(game, "./asset/dino.xpm");
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	//error_exit()
}

void	init_win(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.size.col * PX, 
			game->map.size.row * PX, "so_long");
	//error_exit()
}

void	init_player(t_game *game)
{	
	game->player.move_cnt = 0;
	game->player.item_cnt = 0;
	get_player_pos(game);
}

void	get_player_pos(t_game *game)
{
	int	row;;
	int	col;

	row  = 0;
	while (row < game->map.size.row)
	{
		col = 0;
		while (col < game->map.size.col)
		{
			if (game->map.chunks[row][col] == 'P')				
			{
				game->player.pos.row = row;
				game->player.pos.col = col;
				return;
			}
			++col;
		}
		++row;
	}
}
