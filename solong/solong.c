/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:00:48 by mher              #+#    #+#             */
/*   Updated: 2022/03/25 20:26:01 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx/mlx.h"

#include "get_next_line.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.
typedef struct s_param{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	char	str[3];
}				t_param;

//Only param->x will be used. 
void			param_init(t_param *param)
{
	param->x = 1;
	param->y = 1;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;
	void	*img;
	int		width;
	int		height;

	if (keycode == KEY_W)//Action when W key pressed
	{
		param->y--;
		mlx_clear_window(param->mlx, param->win);
		img = mlx_xpm_file_to_image(param->mlx, "images/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("y: %d\n", param->y);
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		param->y++;
		mlx_clear_window(param->mlx, param->win);
		img = mlx_xpm_file_to_image(param->mlx, "images/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("y: %d\n", param->y);
	}
	if (keycode == KEY_A)//Action when W key pressed
	{
		param->x--;
		mlx_clear_window(param->mlx, param->win);
		img = mlx_xpm_file_to_image(param->mlx, "images/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("x: %d\n", param->x);
	}
	else if (keycode == KEY_D) //Action when S key pressed
	{
		param->x++;
		mlx_clear_window(param->mlx, param->win);
		img = mlx_xpm_file_to_image(param->mlx, "images/dino.xpm", &width, &height);
		mlx_put_image_to_window(param->mlx, param->win, img, param->x * 64, param->y * 64);
		printf("x: %d\n", param->x);
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	return (0);
}


char	*read_map(char *map)
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

void	solong(char *map)
{
	printf("%s\n", read_map(map));
}

int	main(int ac, char **ag)
{
	void	*mlx;
	void	*win;
	void	*img;

	int		img_width;
	int		img_height;

	t_param		param;

	param_init(&param);

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 1000, 1000, "my_mlx");
	printf("-------------------------------\n");
	printf("'W key': Add 1 to x.\n");
	printf("'S key': Subtract 1 from x\n");
	printf("'ESC key': Exit this program\n");
	printf("'Other keys': print current x \n");
	printf("-------------------------------\n");
	printf("Current x = 3\n");
	img = mlx_xpm_file_to_image(param.mlx, "images/dino.xpm", &img_width, &img_height);
	mlx_put_image_to_window(param.mlx, param.win, img, param.x*64, param.y*64);
	mlx_hook(param.win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(param.mlx);

	solong(ag[1]);
	return (0);
}
