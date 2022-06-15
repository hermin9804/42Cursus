/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:19:53 by mher              #+#    #+#             */
/*   Updated: 2022/06/13 19:06:46 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	get_tmp_file_num(void)
{
	static int	tmp_file_num;

	return (tmp_file_num++);
}

char	*get_tmp_file_name(void)
{
	int		tmp_num;
	char	*str_num;
	char	*file_name;

	while (1)
	{
		tmp_num = get_tmp_file_num();
		str_num = ft_itoa(tmp_num);
		file_name = ft_strjoin("tmp_file_", str_num);
		if (is_exist_file(file_name) == 0)
		{
			free(str_num);
			return (file_name);
		}
		free(file_name);
		free(str_num);
	}
}

void	delete_tmp_file(void)
{
	int		tmp_num;
	char	*str_num;
	char	*file_name;

	tmp_num = get_tmp_file_num();
	while (--tmp_num > -1)
	{
		str_num = ft_itoa(tmp_num);
		file_name = ft_strjoin("tmp_file_", str_num);
		if (is_exist_file(file_name))
			unlink(file_name);
		free(str_num);
		free(file_name);
	}
	return ;
}
