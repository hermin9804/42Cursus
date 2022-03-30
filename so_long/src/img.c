/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:56:20 by mher              #+#    #+#             */
/*   Updated: 2022/03/30 14:08:13 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(t_game *game, char *img_path)
{
	void	*img;
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(game->mlx, img_path, &width, &height);
	if (!img)
		error_exit("convertion xpm to img\n");
	return (img);
}

void	ft_put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * PX, y * PX);
	//error_exit()??
}
