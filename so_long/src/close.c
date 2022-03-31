/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:03:14 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 12:38:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *msg)
{
	printf("ERROR: %s\n", msg);
	exit(1);
}

int	close_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("game end!");
	exit(0);
}
