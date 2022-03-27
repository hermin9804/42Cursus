/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:48 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 16:47:33 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_handler(int keycode, t_game *game)
{
	void	*img;
	int		width;
	int		height;

	if (keycode == KEY_W)//Action when W key pressed
	{
		game->y--;
		img = mlx_xpm_file_to_image(game->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->win, img, game->x * PIXEL_SIZE, game->y * PIXEL_SIZE);
		printf("y: %d\n", game->y);
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		game->y++;
		img = mlx_xpm_file_to_image(game->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->win, img, game->x * PIXEL_SIZE, game->y * PIXEL_SIZE);
		printf("y: %d\n", game->y);
	}
	if (keycode == KEY_A)//Action when W key pressed
	{
		game->x--;
		img = mlx_xpm_file_to_image(game->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->win, img, game->x * PIXEL_SIZE, game->y * PIXEL_SIZE);
		printf("x: %d\n", game->x);
	}
	else if (keycode == KEY_D) //Action when S key pressed
	{
		game->x++;
		img = mlx_xpm_file_to_image(game->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->win, img, game->x * PIXEL_SIZE, game->y * PIXEL_SIZE);
		printf("x: %d\n", game->x);
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
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_exit_handler, &game);
	mlx_loop(game.mlx);
}

//int	main(int argc, char **argv)
//{
//	void	*img_dino;
//	void	*img_snow;
//
//	int		img_width;
//	int		img_height;
//
//	int		row;
//	int		col;
//	
//	if (argc !=  2)
//		error_exit("check your argv");
//
//	row = 0;
//	col = 0;
//
//	t_game		game;
//
//	game_init(&game);
//	solong(argv[1], &row, &col);
//
//	game.mlx = mlx_init();
//	game.win = mlx_new_window(game.mlx, col*PIXEL_SIZE, row*PIXEL_SIZE, "my_mlx");
//
//	int i = 0;
//	while (i < col)
//	{
//		int j = 0;
//		while (j < row)
//		{
//			img_snow = mlx_xpm_file_to_image(game.mlx, "asset/snow.xpm", &img_width, &img_height);
//			mlx_put_image_to_window(game.mlx, game.win, img_snow, i*PIXEL_SIZE, j*PIXEL_SIZE);
//			j++;
//		}
//		i++;
//	}
//	img_dino = mlx_xpm_file_to_image(game.mlx, "asset/dino.xpm", &img_width, &img_height);
//	mlx_put_image_to_window(game.mlx, game.win, img_dino, game.x*PIXEL_SIZE, game.y*PIXEL_SIZE);
//	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
//	mlx_loop(game.mlx);
//
//	return (0);
//}
