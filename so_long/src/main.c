/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:48 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 03:07:44 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	param_init(t_param *param)
{
	param->x = 1;
	param->y = 1;
}

int	key_press(int keycode, t_param *param)
{
	void	*img;
	int		width;
	int		height;

	if (keycode == KEY_W)//Action when W key pressed
	{
		param->y--;
		img = mlx_xpm_file_to_image(param->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("y: %d\n", param->y);
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		param->y++;
		img = mlx_xpm_file_to_image(param->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("y: %d\n", param->y);
	}
	if (keycode == KEY_A)//Action when W key pressed
	{
		param->x--;
		img = mlx_xpm_file_to_image(param->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("x: %d\n", param->x);
	}
	else if (keycode == KEY_D) //Action when S key pressed
	{
		param->x++;
		img = mlx_xpm_file_to_image(param->mlx, "asset/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("x: %d\n", param->x);
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	return (0);
}


char	*read_map(char *map, int *row)
{
	int		fd;
	char	*line;
	char	*total_map;
	char	*tmp;

	total_map = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		*row += 1;	
		tmp = total_map;
		line = get_next_line(fd);
		if (!line)
			break;
		total_map = ft_strjoin(tmp, line);
		if (total_map == 0)
			return (0);
	}
	return (total_map);
}

void	solong(char *ag, int *row, int *col)
{
	char	*tmp;
	char	**map;
	
	tmp = read_map(ag, row);
	map = ft_split(tmp, '\n');
	*col = ft_strlen(map[0]);
}

int	main(int argc, char **argv)
{
	void	*img_dino;
	void	*img_snow;

	int		img_width;
	int		img_height;

	int		row;
	int		col;
	
	if (argc !=  2)
		error_exit("check your argv");

	row = 0;
	col = 0;

	t_param		param;

	param_init(&param);
	solong(argv[1], &row, &col);

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, col*64, row*64, "my_mlx");

	int i = 0;
	while (i < col)
	{
		int j = 0;
		while (j < row)
		{
			img_snow = mlx_xpm_file_to_image(param.mlx, "asset/snow.xpm", &img_width, &img_height);
			mlx_put_image_to_window(param.mlx, param.win, img_snow, i*64, j*64);
			j++;
		}
		i++;
	}
	img_dino = mlx_xpm_file_to_image(param.mlx, "asset/dino.xpm", &img_width, &img_height);
	mlx_put_image_to_window(param.mlx, param.win, img_dino, param.x*64, param.y*64);
	mlx_hook(param.win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(param.mlx);

	return (0);
}
