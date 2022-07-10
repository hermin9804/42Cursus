/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:00:29 by mher              #+#    #+#             */
/*   Updated: 2022/07/10 22:41:03 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	return_with_free(pid_t *pids, int return_value)
{
	free(pids);
	return (return_value);
}

static int	wait_end(t_philo *philo, pid_t *pids)
{
	int				status;
	unsigned int	i;

	waitpid(-1, &status, 0);
	i = 0;
	while (i < philo->info->nop)
	{
		kill(pids[i], SIGTERM);
		++i;
	}
	i = philo->info->nop;
	while (i--)
		sem_post(philo->shared->full_philos);
	return (0);
}

int	run_simulation(t_philo *philo)
{
	pid_t			*pids;
	unsigned int	i;

	pids = (pid_t *)malloc(sizeof(pid_t) * philo->info->nop);
	if (pids == NULL)
		return (1);
	philo->info->start_at = get_current_time_ms();
	philo->last_eat_time = philo->info->start_at;
	i = 0;
	while (i < philo->info->nop)
	{
		philo->id = i + 1;
		pids[i] = fork();
		if (pids[i] == -1)
			return (return_with_free(pids, 1));
		else if (pids[i++] == 0)
			exit(do_routine(philo));
	}
	if (observe_full(philo))
		return (return_with_free(pids, 1));
	wait_end(philo, pids);
	return (return_with_free(pids, 0));
}
