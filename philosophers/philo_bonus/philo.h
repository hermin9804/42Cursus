/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/27 15:34:53 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define INT_MIN	-2147483648
# define INT_MAX	2147483647

# define C_RED		"\033[1;31m"
# define C_GREN		"\033[1;32m"
# define C_YLLW		"\033[1;33m"
# define C_BLUE		"\033[1;34m"
# define C_PRPL		"\033[0;35m"
# define C_RESET	"\033[0m"

# define TIME_FOR_CONTEXT_SWITCHING 1000

enum e_log_type
{
	FORK,
	EAT,
	SLEEP,
	THINK,
};

enum e_exit_status
{
	SUCCESS,
	PARSE_FAIL,
	SEMAPHORE_FAIL,
	RUNTIME_FAIL
};

typedef struct s_info
{
	unsigned int	nop;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	nome;
	time_t			start_at;
}	t_info;

typedef struct s_shared
{
	sem_t			*forks_lock;
	sem_t			*forks;
	sem_t			*end_lock;
	sem_t			*full_philos;
}	t_shared;

typedef struct s_philo
{
	pid_t			*pids;
	unsigned int	id;
	unsigned int	eat_count;
	time_t			last_eat_time;
	sem_t			*event_lock;
	t_info			*info;
	t_shared		*shared;
}	t_philo;

// simulation
int		run_simulation(t_philo *philo);
void	*monitor_dead(void *_philo);
void	*monitor_full(void *_philo);

// routine
int		do_routine(t_philo *philo);
void	take_forks(t_philo *philo);
void	release_forks(t_philo *philo);
void	set_sem_name(char *sem_name, unsigned int id);

// parser
int		parse_args(t_info *info, int argc, char *argv[]);

// semaphore
int		init_semaphore(t_shared *shared, t_info *info);
int		open_semaphore(char *name, unsigned int value, sem_t **sem_out);
int		destroy_semaphore(t_shared *shared);

// utils
size_t	ft_strlen(const char *s);
time_t	get_current_time_ms(void);
time_t	get_passed_time_ms(time_t start_time);
void	snooze(time_t time_to_wait);
void	print_log(t_philo *philo, enum e_log_type type);

#endif
