/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:12:07 by mher              #+#    #+#             */
/*   Updated: 2022/05/07 20:01:50 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	get_here_doc_input(t_arg *arg)
{
	char	*line;
	char	*lim;
	size_t	len;

	lim = arg->argv[2];
	len = ft_strlen(lim);
	while (1)
	{
		write_handle_error(STDOUT_FILENO, "pipe heredoc> ", 14);
		line = get_next_line(STDIN_FILENO);
		if (ft_strlen(line) - 1 == len && !ft_strncmp(line, lim, len))
		{
			free(line);
			close_unused_fd(arg);
			exit(EXIT_SUCCESS);
		}
		write_handle_error(arg->b[WRITE], line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_arg *arg)
{
	if (ft_strlen(arg->argv[1]) != 8 || ft_strncmp(arg->argv[1], "here_doc", 8))
		return ;
	if (pipe(arg->b) < 0)
		exit_with_perror("pipe fail", EXIT_FAILURE);
	arg->pid = fork();
	if (arg->pid == 0)
		get_here_doc_input(arg);
	else
	{
		close_unused_fd(arg);
		arg->a[READ] = arg->b[READ];
		arg->o_flag = O_WRONLY | O_CREAT | O_APPEND;
		arg->proc_cnt = 3;
	}
}
