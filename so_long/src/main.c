/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:48 by mher              #+#    #+#             */
/*   Updated: 2022/03/29 20:39:50 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_handler(int keycode, t_game *game)
{
	if (keycode == KEY_W)//Action when W key pressed
	{
		game->player.pos.row--;
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.dino, game->player.pos.col * PX, game->player.pos.row * PX);
		printf("x: %d, y: %d\n", game->player.pos.col, game->player.pos.row);
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		game->player.pos.row++;
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.dino, game->player.pos.col * PX, game->player.pos.row* PX);
		printf("x: %d, y: %d\n", game->player.pos.col, game->player.pos.row);
	}
	if (keycode == KEY_A)//Action when W key pressed
	{
		game->player.pos.col--;
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.dino, game->player.pos.col * PX, game->player.pos.row * PX);
		printf("x: %d, y: %d\n", game->player.pos.col, game->player.pos.row);
	}
	else if (keycode == KEY_D) //Action when S key pressed
	{
		game->player.pos.col++;
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.dino, game->player.pos.col * PX, game->player.pos.row * PX);
		printf("x: %d, y: %d\n", game->player.pos.col, game->player.pos.row);
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	
	if (argc !=  2)
		error_exit("check argv input");
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press_handler, &game);
//	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_exit_handler, &game);

	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");//
	
	mlx_loop(game.mlx);
}

