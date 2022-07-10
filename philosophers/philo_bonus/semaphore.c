/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/07/10 23:17:11 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	close_semaphore(t_shared *shared, t_info *info)
{
	unsigned int	i;

	if (shared->forks_lock != 0)
		sem_close(shared->forks_lock);
	if (shared->forks != 0)
		sem_close(shared->forks);
	if (shared->end_lock != 0)
		sem_close(shared->end_lock);
	if (shared->full_philos != 0)
		sem_close(shared->full_philos);
	i = 1;
	while (i <= info->nop)
	{
		if (shared->event_lock[i] != 0)
			sem_close(shared->event_lock[i]);
		++i;
	}
}

static void	unlink_semaphore(t_shared *shared, t_info *info)
{
	unsigned int	i;

	if (shared->forks_lock != 0)
		sem_unlink("forks_lock");
	if (shared->forks != 0)
		sem_unlink("forks");
	if (shared->end_lock != 0)
		sem_unlink("end_lock");
	if (shared->full_philos != 0)
		sem_unlink("full_philos");
	i = 1;
	while (i <= info->nop)
	{
		if (shared->event_lock[i] != 0)
			sem_close(shared->event_lock[i]);
		++i;
	}
}

int	open_semaphore(char *name, unsigned int value, sem_t **sem_out)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem == SEM_FAILED)
		return (1);
	*sem_out = sem;
	return (0);
}

int	destroy_semaphore(t_shared *shared, t_info *info)
{
	close_semaphore(shared, info);
	unlink_semaphore(shared, info);
	return (1);
}

int	init_semaphore(t_shared *shared, t_info *info)
{
	unsigned int	i;
	char			sem_name[21];

	memset(shared, 0, sizeof(t_shared));
	if (open_semaphore("forks_lock", info->nop / 2, &(shared->forks_lock)))
		return (destroy_semaphore(shared, info));
	if (open_semaphore("forks", info->nop, &(shared->forks)))
		return (destroy_semaphore(shared, info));
	if (open_semaphore("end_lock", 1, &(shared->end_lock)))
		return (destroy_semaphore(shared, info));
	if (open_semaphore("full_philos", 0, &(shared->full_philos)))
		return (destroy_semaphore(shared, info));
	shared->event_lock = (sem_t **)malloc(sizeof(sem_t) * (info->nop + 1));
	if (shared->event_lock == NULL)
		return (1);
	i = 1;
	while (i <= info->nop)
	{
		set_sem_name(sem_name, i);
		if (open_semaphore(sem_name, 1, &(shared->event_lock[i])))
			return (destroy_semaphore(shared, info));
		++i;
	}
	return (0);
}
