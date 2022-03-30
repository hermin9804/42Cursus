/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:51:03 by mher              #+#    #+#             */
/*   Updated: 2022/03/30 18:09:33 by mher             ###   ########.fr       */
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
	int	col;
	int	row;

	col = pos.col;
	row = pos.row;
	ft_put_img(game, game->imgs.snow, col, row);
	if (game->map.chunks[row][col] == '1')
		ft_put_img(game, game->imgs.wall, col, row);
	else if (game->map.chunks[row][col] == 'C')
		ft_put_img(game, game->imgs.sign, col, row);
	else if (game->map.chunks[row][col] == 'E')
		ft_put_img(game, game->imgs.home, col, row);
	else if (game->map.chunks[row][col] == 'P')
		ft_put_img(game, game->imgs.dino, col, row);
}
