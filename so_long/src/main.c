/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:48 by mher              #+#    #+#             */
/*   Updated: 2022/03/30 12:41:38 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	
	if (argc !=  2)
		error_exit("check argv input");
	init_game(&game, argv[1]);
	draw_map(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
//	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_exit, &game);

	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");//
	
	mlx_loop(game.mlx);
}

