/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:23:31 by mher              #+#    #+#             */
/*   Updated: 2022/06/19 02:35:39 by mher             ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				tte;
	int				tts;
	int				eat_count;
	int				already_full;
	time_t			last_eat_time;
	time_t			start_eat_time;

	pthread_mutex_t	event_lock;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;

	char			*is_end;	// ??
	pthread_mutex_t	*is_end_lock;
}	t_philo;

typedef struct	s_shared
{
	pthread_mutex_t	*is_end_lock;
	char			*is_end;
} t_shared;

// parser
int		parse_args(t_info *info, int argc, char *argv[]);

// allocator
int		alloc_philo(t_philo *philo, t_info *info);

// initalizer
int		init_philo(t_philo *philo, t_info *info);
int		init_mutex(t_philo *philo, t_shared *shared_var, t_info *info);

// utils
size_t	ft_strlen(const char *s);
int		ft_isdigit(const char c);
int		ft_isspace(const char c);
int		ft_atoi(const char *str);
void	*ft_free(void *ptr);

#endif
