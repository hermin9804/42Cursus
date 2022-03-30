/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:41:08 by mher              #+#    #+#             */
/*   Updated: 2022/03/30 18:22:01 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->map.chunks[dir.row][dir.col] = '0';
	game->player.pos = dir;
	printf("move cnt: %d\n", game->player.move_cnt);
}

void	move_to_snow(t_game *game, t_pos dir)
{
	game->player.move_cnt++;
	ft_put_img(game, game->imgs.snow, game->player.pos.col, game->player.pos.row);
	ft_put_img(game, game->imgs.dino, dir.col, dir.row);
	game->map.chunks[game->player.pos.row][game->player.pos.col] = '0';
	game->player.pos = dir;
	printf("move cnt: %d\n", game->player.move_cnt);
}

void	move_to_home(t_game *game)
{
	if (game->player.item_cnt == game->map.flags.sign)
	{
		system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");//
		exit(0);//
	}
}
