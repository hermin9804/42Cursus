/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 13:16:54 by mher              #+#    #+#             */
/*   Updated: 2022/03/31 01:00:09 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_path(const char *map_path, const char *suffix)
{
	int		p_len;
	int		s_len;

	p_len = ft_strlen(map_path);
	s_len = ft_strlen(suffix);
	if (p_len < 4)
		error_exit("invalid file suffix.");
	if (ft_strncmp(suffix, &map_path[p_len - s_len], s_len))
		error_exit("invalid file suffix.");
}

void	check_rectangul(t_map *map)
{
	int	i;
	int	diff;

	i = 0;
	while (i < map->size.row)
	{
		diff = ft_strlen(map->chunks[i]);
		if (map->size.col != diff)
			error_exit("map is not rectangul.");
		++i;
	}
}

void	check_surround(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.col)
	{
		if (map->chunks[0][i] != '1')
			error_exit("map is not surrounded top wall.");
		if (map->chunks[map->size.row - 1][i] != '1')
			error_exit("map is not surrounded bottom wall.");
		++i;
	}
	i = 0;
	while (i < map->size.row)
	{
		if (map->chunks[i][0] != '1')
			error_exit("map is not surrounded left wall.");
		if (map->chunks[i][map->size.col - 1] != '1')
			error_exit("map is not surrounded right wall.");
		++i;
	}
}

void	check_components(t_map *map)
{
	const char	*components = "10CEP";
	int			row;
	int			col;

	ft_bzero(&map->flags, sizeof(map->flags));
	row = 0;
	while (row < map->size.row)
	{
		col = 0;
		while(col < map->size.col)
		{
			if (!ft_strchr(components, map->chunks[row][col]))
				error_exit("invlalid component.");
			if (map->chunks[row][col] == 'C')
			 	map->flags.sign++;
			else if (map->chunks[row][col] == 'E')
				map->flags.home++;
			else if (map->chunks[row][col] == 'P')
				map->flags.dino++;
			++col;
		}
		++row;
	}
	if (map->flags.sign < 1 || map->flags.home < 1 || map->flags.dino != 1)
		error_exit("invlalid component count.");
}
