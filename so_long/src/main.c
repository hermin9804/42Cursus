/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:48 by mher              #+#    #+#             */
/*   Updated: 2022/03/30 02:50:24 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	const int transform[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_W)
		move(game, transform[0]);
	else if (keycode == KEY_S)
		move(game, transform[1]);
	else if (keycode == KEY_A)
		move(game, transform[2]);
	else if (keycode == KEY_D)
		move(game, transform[3]);
	return (0);
}

void	move(t_game *game, const int transform[2])
{	
	t_pos	dir;

	dir.row = game->player.pos.row + transform[0];
	dir.col = game->player.pos.col + transform[1];
	if (game->map.chunks[dir.row][dir.col] == '1')
		return ;
	else if (game->map.chunks[dir.row][dir.col] == 'C')
		return (move_to_item(game, dir));
	else if (game->map.chunks[dir.row][dir.col] == '0')
		return (move_to_snow(game, dir));
	else if (game->map.chunks[dir.row][dir.col] == 'E')
		return (move_to_home(game));
}

void	move_to_item(t_game *game, t_pos dir)
{
	game->player.item_cnt++;
	game->player.move_cnt++;
	ft_put_img(game, game->imgs.snow, game->player.pos.col, game->player.pos.row);
	ft_put_img(game, game->imgs.snow, dir.col, dir.row);
	ft_put_img(game, game->imgs.dino, dir.col, dir.row);
	game->player.pos = dir;
	printf("move cnt: %d\n", game->player.move_cnt);
}

void	move_to_snow(t_game *game, t_pos dir)
{
	game->player.move_cnt++;
	ft_put_img(game, game->imgs.snow, game->player.pos.col, game->player.pos.row);
	ft_put_img(game, game->imgs.dino, dir.col, dir.row);
	game->player.pos = dir;
	printf("move cnt: %d\n", game->player.move_cnt);
}

void	move_to_home(t_game *game)
{
	if (game->player.item_cnt == game->doorock)
		exit(0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	
	if (argc !=  2)
		error_exit("check argv input");
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
//	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_exit_handler, &game);

	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");//
	
	mlx_loop(game.mlx);
}

