/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:23:57 by mher              #+#    #+#             */
/*   Updated: 2022/03/27 01:24:19 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../lib/libft/include/libft.h"
#include "../lib/libgnl/include/get_next_line.h"
#include "../lib/libmlx/mlx.h"

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

typedef struct s_param{
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	char	str[3];
}				t_param;

#endif
