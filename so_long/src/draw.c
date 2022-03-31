/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:03 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 12:06:25 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	t_pos	pos;

	pos.row = 0;
	while (pos.row < game->map.size.row)
	{
		pos.col = 0;
		while (pos.col < game->map.size.col)
		{
			draw_component(game, pos);
			pos.col++;
		}
		pos.row++;
	}
}

void	draw_component(t_game *game, t_pos pos)
{
	ft_put_img(game, game->imgs.snow, pos);
	if (game->map.chunks[pos.row][pos.col] == '1')
		ft_put_img(game, game->imgs.wall, pos);
	else if (game->map.chunks[pos.row][pos.col] == 'C')
		ft_put_img(game, game->imgs.sign, pos);
	else if (game->map.chunks[pos.row][pos.col] == 'E')
		ft_put_img(game, game->imgs.home, pos);
	else if (game->map.chunks[pos.row][pos.col] == 'P')
		ft_put_img(game, game->imgs.dino, pos);
}
