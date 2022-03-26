/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:23:57 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 03:09:46 by mher             ###   ########.fr       */
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

# define PIXEL_SIZE   64

# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_EXIT   17

# define KEY_ESC    53
# define KEY_W      13
# define KEY_S      1
# define KEY_A      0
# define KEY_D      2

typedef struct s_param{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
}	t_param;

void	error_exit(const char *msg);

#endif
