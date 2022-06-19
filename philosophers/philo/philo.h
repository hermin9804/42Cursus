/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/19 15:19:38 by mher             ###   ########.fr       */
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
	int		nop;
	int		ttd;
	int		tte;
	int		tts;
	int		nome;
	time_t	start_time;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_count;
	int				already_full;
	time_t			last_eat_time;
	time_t			start_eat_time;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_info			*info;
}	t_philo;

// parser
int		parse_args(t_info *info, int argc, char *argv[]);

// allocator
int		alloc_philo(t_philo *philo, t_info *info);

// initalizer
int		init_philo(t_philo *philo, t_info *info);
int		init_mutex(t_philo *philo, t_info *info);

// utils
size_t	ft_strlen(const char *s);
int		ft_isdigit(const char c);
int		ft_isspace(const char c);
int		ft_atoi(const char *str);
void	*ft_free(void *ptr);

#endif
