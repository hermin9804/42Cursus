/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/20 13:59:00 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

enum e_exit_status
{
	SUCCESS = 0,
	PARSE_FAIL,
	MALLOC_FAIL,
	MUTEX_FAIL,
	RUNTIME_FAIL
};

typedef struct s_info
{
	unsigned int	nop;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	nome;
	time_t			start_time;
}	t_info;

typedef struct s_shared
{
	pthread_mutex_t	is_end_lock;
	int				is_end;
}	t_shared;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_count;
	int				already_full;
	time_t			last_eat_time;
	time_t			start_eat_time;
	pthread_mutex_t	event_lock;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_info			*info;
	t_shared		*shared;
}	t_philo;

// simulation
int		run_simulation(t_philo *philos, t_info *info);
void	*monitor_dead(void *philo);

// routine
void	*do_routine(void *philo);

// parser
int		parse_args(t_info *info, int argc, char *argv[]);

// allocator
int		alloc_philo(t_philo **philo, t_info *info);

// initalizer 
void	init_philo(t_philo *philo, t_info *info, t_shared *shared);
int		init_mutex(t_philo *philo, t_info *info, t_shared *shared);

// destroyer
void	destroy_mutex(t_philo *philo);

// utils
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_free(void *ptr);
time_t	get_time_ms(void);
time_t	get_passed_time_ms(time_t start_time);

#endif
