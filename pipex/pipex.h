/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:26:02 by mher              #+#    #+#             */
/*   Updated: 2022/04/30 01:03:47 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ 0
# define WRITE 1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/include/libft.h"

typedef struct s_arg
{
	int		infile;
	int		outfile;
	char	**path;
	char	*cmd1;
	char	*cmd2;
	char	**cmd_arg1;
	char	**cmd_arg2;
	int	pipe[2];
	pid_t	child_pid;
	
}	t_arg;

#endif
