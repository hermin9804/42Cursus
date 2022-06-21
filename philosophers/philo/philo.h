/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/22 02:16:50 by mher             ###   ########.fr       */
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

# define C_RED		"\033[1;31m"
# define C_GREN		"\033[1;32m"
# define C_YLLW		"\033[1;33m"
# define C_BLUE		"\033[1;34m"
# define C_PRPL		"\033[0;35m"
# define C_RESET	"\033[0m"

# define FOR_OTHER_PHILOS 1000

enum e_log_type
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
};

enum e_exit_status
{
	SUCCESS,
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
}	t_info;

typedef struct s_end_state
{
	pthread_mutex_t	is_end_lock;
	int				is_end;
}	t_end_state;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	eat_count;
	time_t			last_eat_time;
	time_t			start_time;
	pthread_mutex_t	event_lock;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_info			*info;
	t_end_state		*end_state;
}	t_philo;

// simulation
int		run_simulation(t_philo *philos, t_info *info);
void	*monitor_philos(void *_philos);
void	stop_simulation(t_philo *philo);
int		is_end_simulation(t_philo *philo);

// routine
void	*do_routine(void *philo);
void	take_forks(t_philo *philo);
void	release_forks(t_philo *philo);

// parser
int		parse_args(t_info *info, int argc, char *argv[]);

// allocator
int		alloc_philo(t_philo **philo, t_info *info);

// initalizer 
void	init_philo(t_philo *philo, t_info *info, t_end_state *end_state);
int		init_mutex(t_philo *philo, t_info *info, t_end_state *end_state);

// destroyer
void	destroy_mutex(t_philo *philo);

// utils
size_t	ft_strlen(const char *s);
time_t	get_time_ms(void);
time_t	get_passed_time_ms(time_t start_time);
void	busy_wait(time_t start, time_t wait_time);
void	print_log(t_philo *philo, enum e_log_type type);

#endif
