/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:11:12 by mher              #+#    #+#             */
/*   Updated: 2022/05/06 01:49:14 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_arg *arg, int argc, char *argv[], char *envp[])
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	arg->first_arg = argv[1];
	arg->last_arg = argv[argc - 1];
	arg->path_env = get_path_env(envp);
	if (arg->path_env == 0)
		error_exit("PATH not found", EXIT_FAILURE);
	arg->proc_cnt = 1;
	here_doc(arg);
}
