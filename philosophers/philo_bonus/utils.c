/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:42:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/27 15:36:40 by mher             ###   ########.fr       */
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

time_t	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t	get_passed_time_ms(time_t start_time)
{
	return (get_current_time_ms() - start_time);
}

void	snooze(time_t time_to_wait)
{
	time_t	start_time;

	start_time = get_current_time_ms();
	while (get_passed_time_ms(start_time) < time_to_wait)
		usleep(TIME_FOR_CONTEXT_SWITCHING);
}

void	print_log(t_philo *philo, enum e_log_type type)
{
	time_t 			time_stamp;
	unsigned int	id;

	time_stamp = get_passed_time_ms(philo->info->start_at);
	id = philo->id;
	sem_wait(philo->shared->end_lock);
	if (type == FORK)
		printf(C_BLUE "%ld %u has taken a fork\n" C_RESET, time_stamp, id);
	else if (type == EAT)
		printf(C_RED "%ld %u is eating\n" C_RESET, time_stamp, id);
	else if (type == SLEEP)
		printf(C_GREN "%ld %u is sleeping\n" C_RESET, time_stamp, id);
	else if (type == THINK)
		printf(C_YLLW "%ld %u is thinking\n" C_RESET, time_stamp, id);
	sem_post(philo->shared->end_lock);
}
