/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:11:12 by mher              #+#    #+#             */
/*   Updated: 2022/05/05 16:11:41 by mher             ###   ########.fr       */
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
		exit(EXIT_FAILURE); //error_exit();
	arg->in_fd = open(argv[1], O_RDONLY);
	if (arg->in_fd == -1)
		exit(EXIT_FAILURE); //error_exit();
	arg->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->out_fd == -1)
		exit(EXIT_FAILURE); //error_exit();
	arg->proc_cnt = 1;
}
