/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/18 23:40:36 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

enum e_exit_status
{
	SUCCESS = 0,
	PARSE_FAIL,
	ALLOC_FAIL,
	MUTEX_FAIL,
	RUNTIME_FAIL
};

typedef struct s_info
{
	int	nop;
	int	ttd;
	int	tte;
	int	tts;
	int	nome;
}	t_info;

typedef struct s_vars
{
	int	dead_flag;
	int	full_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	key; // ??
}	t_vars;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	index;
	time_t			last_eat_time;
	time_t			start_eat_time;
	unsigned int	eat_count;
	unsigned int	already_full;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

// parser
int		parse_args(t_info *info, int argc, char *argv[]);
int		init_vars(t_vars *vars, const t_info info);

// utils
size_t	ft_strlen(const char *s);
int		ft_isdigit(const char c);
int		ft_isspace(const char c);
int		ft_atoi(const char *str);

#endif
