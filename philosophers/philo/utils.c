/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:42:43 by mher              #+#    #+#             */
/*   Updated: 2022/06/21 16:17:58 by mher             ###   ########.fr       */
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

void	print_log(t_philo *philo, const char *msg, enum e_color color_num)
{
	time_t 			time_stamp;
	unsigned int	id;

	time_stamp = get_passed_time_ms(philo->start_time);
	id = philo->id;
	pthread_mutex_lock(&(philo->shared->is_end_lock));
	if (!philo->shared->is_end)
	{
		if (color_num == BLUE)
			printf(COLOR_BLUE "%ld %u %s\n" COLOR_RESET, time_stamp, id, msg);
		else if (color_num == RED)
			printf(COLOR_RED "%ld %u %s\n" COLOR_RESET, time_stamp, id, msg);
		else if (color_num == GREEN)
			printf(COLOR_GREEN "%ld %u %s\n" COLOR_RESET, time_stamp, id, msg);
		else if (color_num == YELLOW)
			printf(COLOR_YELLOW "%ld %u %s\n" COLOR_RESET, time_stamp, id, msg);
	}
	pthread_mutex_unlock(&(philo->shared->is_end_lock));
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
//void	pass_time_ms(t_philo *philo, time_t wait_time)
//{
//}
