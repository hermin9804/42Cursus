/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mher <mher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:45:22 by mher              #+#    #+#             */
/*   Updated: 2022/05/15 19:53:47 by mher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	p_function(void *data)
{
	pid_t 		pid;
	pthread_t	tid;
	char 		*thread_name;
	int		i;

	pid = getpid();
	tid = pthread_self();
	thread_name = (char *)data;
	i = 0;
	while (i < 3)
	{
    		printf("thread name : %s, tid : %x, pid : %u\n", thread_name, 
				(unsigned int)tid, (unsigned int)pid);
		++i;
		sleep(1);
	}
}

int main()
{
	pthread_t	pthread[2];
	int		thr_id;
	int		status;
	const char *p1 = "thread_1";
	const char *p2 = "thread_2";
	const char *p3 = "thread_3";
	void *p = &p_function;

	sleep(1);
	thr_id = pthread_create(&pthread[0], NULL, p, (void*)p1);
	if (thr_id < 0)
	{
		perror("pthread1 cread error");
		exit(EXIT_FAILURE);
	}
	p_function((void *)p3);
	pthread_join(pthread[0], (void **)&status);
	pthread_join(pthread[1], (void **)&status);
	printf("end??\n");
	return 0;
}
