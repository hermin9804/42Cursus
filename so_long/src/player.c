/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:06:04 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 12:09:02 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.size.row)
	{
		col = 0;
		while (col < game->map.size.col)
		{
			if (game->map.chunks[row][col] == 'P')
			{
				game->player.pos.row = row;
				game->player.pos.col = col;
				return ;
			}
			++col;
		}
		++row;
	}
}
