/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:06:04 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 17:42:11 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*get_img(t_game, const char *img_path)
{
	void	*img;
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(game->mlx, img_path, &width, &height);
	if (!img)
		error_exit("convertion xpm to img\n");
	return (img);
}
