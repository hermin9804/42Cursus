/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/18 18:30:04 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h> //memset 쓰나??
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

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
	int	full_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	key; // ??
	time_t			start_time;
}	t_vars;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	index;
	time_t			last_eat_time;
	unsigned int	eat_count;
	unsigned int	already_full;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

// initalizer
int	init_info(t_info *info, int argc, char *argv[]);
int	init_vars(t_vars *vears, t_info info);

// utils
int check_valid_atoi(const char *str, int *num);
size_t	ft_strlen(const char *s);

#endif
