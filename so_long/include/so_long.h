/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:23:57 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 16:23:09 by mher             ###   ########.fr       */
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
	void	*sign_img;
	void	*home_img;
	void	*dino_img;
	void	*snow_img;
	void	*wall_img;
}	t_imgs;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	t_pos	cur_pos;
	int	move_count;
	int	item_count;
}	t_player;

typedef struct s_map;
{
	char	**map;
	int	row_size;
	int	col_size;
}

typedef struct s_game{
	t_map		map;
	t_player	player;	
	t_imgs		imgs;
	void		*mlx;
	void		*win;
}	t_game;

void	error_exit(const char *msg);

#endif
