/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:23:57 by mher              #+#    #+#             */
/*   Updated: 2022/03/29 20:29:22 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> //
# include <unistd.h>//

# include <fcntl.h>
# include "../lib/libft/include/libft.h"
# include "../lib/libgnl/include/get_next_line.h"
# include "../lib/libmlx/mlx.h"


# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_EXIT   17

# define KEY_ESC    53
# define KEY_W      13
# define KEY_S      1
# define KEY_A      0
# define KEY_D      2

# define PX   64

typedef struct s_imgs
{
	void	*snow;
	void	*wall;
	void	*sign;
	void	*home;
	void	*dino;
}	t_imgs;

typedef struct s_pos
{
	int	col;
	int	row;
}	t_pos;

typedef struct s_player
{
	int	move_cnt;
	int	item_cnt;
	t_pos	pos;
}	t_player;

typedef struct s_map
{
	t_pos	size;
	char	**chunks;
}	t_map;

typedef struct s_game{
	t_map		map;
	t_player	player;	
	t_imgs		imgs;
	void		*mlx;
	void		*win;
}	t_game;

void	error_exit(const char *msg);
void	init_game(t_game *game, const char *map_path);
void	init_map(t_game *game, const char *map_path);
void	init_player(t_game *game);
void	init_img(t_game *game);
void	init_mlx(t_game *game);
void	init_win(t_game *game);

void	get_map_chunks(t_game *game, const char *map_path);
void	get_map_size(t_game *game);

void	*get_img(t_game *game, char *img_path);
void	get_player_pos(t_game *game);


void	draw_map(t_game *game);
void	draw_component(t_game *game, t_pos pos);
void	ft_put_img(t_game *game, void *img, int x, int y);

#endif
