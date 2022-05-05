/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:14:35 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 17:28:45 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_env(char *envp[])
{
	char	*path;

	while (*envp && ft_strncmp("PATH=", *envp, 5))
		++envp;
	if (*envp == NULL)
		exit(EXIT_FAILURE); //error_exit();
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	*get_path_cmd(char **path_env, char *cmd)
{
	int	i;
	char	*ret;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (path_env[i])
	{
		ret = ft_strjoin(path_env[i], tmp);
		if (access(ret, X_OK) == 0)
		{
			free(tmp);
			return (ret);
		}
		free(ret);
		i++;
	}
	free(tmp);
	return (NULL);
}
