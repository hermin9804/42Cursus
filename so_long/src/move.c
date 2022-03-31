/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:41:08 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 14:13:02 by mher             ###   ########.fr       */
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
	ft_put_img(game, game->imgs.snow, game->player.pos);
	ft_put_img(game, game->imgs.snow, dir);
	ft_put_img(game, game->imgs.dino, dir);
	game->map.chunks[dir.row][dir.col] = '0';
	game->map.chunks[game->player.pos.row][game->player.pos.col] = '0';
	game->player.pos = dir;
	printf("movements count: %d\n", game->player.move_cnt);
}

void	move_to_snow(t_game *game, t_pos dir)
{
	game->player.move_cnt++;
	ft_put_img(game, game->imgs.snow, game->player.pos);
	ft_put_img(game, game->imgs.dino, dir);
	game->map.chunks[game->player.pos.row][game->player.pos.col] = '0';
	game->player.pos = dir;
	printf("movements count: %d\n", game->player.move_cnt);
}

void	move_to_home(t_game *game)
{
	if (game->player.item_cnt == game->map.flags.sign)
		close_exit(game);
}
