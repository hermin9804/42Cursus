/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:39:00 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 11:51:05 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	const int	transform[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	if (keycode == KEY_ESC)
		close_exit(game);
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
