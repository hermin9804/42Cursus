/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:36:35 by mher              #+#    #+#             */
/*   Updated: 2022/06/26 02:07:18 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void close_semaphore(t_shared *shared)
{
	if (shared->forks_lock != 0)
		sem_close(shared->forks_lock);
	if (shared->forks != 0)
		sem_close(shared->forks);
	if (shared->is_end_lock != 0)
		sem_close(shared->is_end_lock);
}

static void	unlink_semaphore(t_shared *shared)
{
	if (shared->forks_lock != 0)
		sem_unlink("forks_lock");
	if (shared->forks != 0)
		sem_unlink("forks");
	if (shared->is_end_lock != 0)
		sem_unlink("is_end_lock");
}

int	open_semaphore(char *name, unsigned int value, sem_t **sem_out)
{
	sem_t *sem;

	// todo: options 공부
	sem = sem_open(name, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, value);
	if (sem == SEM_FAILED)
		return (1); 
	*sem_out = sem;
	return (0);
}

int	destroy_semaphore(t_shared *shared)
{
	close_semaphore(shared);
	unlink_semaphore(shared);
	return (1);
}

int	init_semaphore(t_shared *shared, t_info *info)
{
	memset(shared, 0, sizeof(t_shared));
	if (open_semaphore("forks_lock", info->nop / 2, &(shared->forks_lock)))
		return (destroy_semaphore(shared));
	if (open_semaphore("forks", info->nop, &(shared->forks)))
		return (destroy_semaphore(shared));
	if (open_semaphore("is_end_lock", 1, &(shared->is_end_lock)))
		return (destroy_semaphore(shared));
	return (0);
}
