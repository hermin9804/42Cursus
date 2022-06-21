/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:42:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/21 18:43:38 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		++i;
		++s;
	}
	return (i);
}

time_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t	get_passed_time_ms(time_t start_time)
{
	return (get_time_ms() - start_time);
}

// TODO: 스핀락으로 하면 뭐가 좋지?
void	busy_wait(time_t start, time_t wait_time)
{
	while (1)
	{
		if (wait_time <= get_passed_time_ms(start))
			break ;
	}
}

void	print_log(t_philo *philo, enum e_log_type type)
{
	time_t 			time_stamp;
	unsigned int	id;

	time_stamp = get_passed_time_ms(philo->start_time);
	id = philo->id;
	pthread_mutex_lock(&(philo->shared->is_end_lock));
	if (!philo->shared->is_end)
	{
		if (type == FORK)
			printf(C_BLUE "%ld %u has taken a fork\n" C_RESET, time_stamp, id);
		else if (type == EAT)
			printf(C_RED "%ld %u is eating\n" C_RESET, time_stamp, id);
		else if (type == SLEEP)
			printf(C_GREN "%ld %u is sleeping\n" C_RESET, time_stamp, id);
		else if (type == THINK)
			printf(C_YLLW "%ld %u is thinking\n" C_RESET, time_stamp, id);
		else if (type == DEAD)
			printf(C_PRPL "%ld %u died\n" C_RESET, time_stamp, id);
	}
	pthread_mutex_unlock(&(philo->shared->is_end_lock));
}
