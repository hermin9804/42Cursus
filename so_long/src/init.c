/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:47:18 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 11:50:41 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_path)
{
	init_map(game, map_path);
	init_player(game);
	init_mlx_win(game);
	init_img(game);
}

void	init_map(t_game *game, const char *map_path)
{
	check_map_path(map_path, ".ber");
	get_map_chunks(game, map_path);
	get_map_size(&game->map);
	check_rectangul(&game->map);
	check_surround(&game->map);
	check_components(&game->map);
}

void	init_img(t_game *game)
{
	game->imgs.snow = get_img(game, "./asset/snow.xpm");
	game->imgs.wall = get_img(game, "./asset/wall.xpm");
	game->imgs.sign = get_img(game, "./asset/sign.xpm");
	game->imgs.home = get_img(game, "./asset/home.xpm");
	game->imgs.dino = get_img(game, "./asset/dino.xpm");
}

void	init_mlx_win(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("failed init mlx");
	game->win = mlx_new_window(game->mlx, game->map.size.col * PX,
			game->map.size.row * PX, "so_long");
	if (!game->win)
		error_exit("failed init win");
}

void	init_player(t_game *game)
{	
	game->player.move_cnt = 0;
	game->player.item_cnt = 0;
	get_player_pos(game);
}
