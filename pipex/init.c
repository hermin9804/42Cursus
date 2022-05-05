/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:11:12 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 22:24:08 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_arg *arg, int argc, char *argv[], char *envp[])
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	arg->path_env = get_path_env(envp);
	if (arg->path_env == 0)
		error_exit("PATH not found", EXIT_FAILURE);
	arg->in_fd = open(argv[1], O_RDONLY);
	if (arg->in_fd == -1)
		perror_exit("open fail", EXIT_FAILURE);
	arg->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->out_fd == -1)
		perror_exit("open fail", EXIT_FAILURE);
	arg->proc_cnt = 1;
}
