#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFF 1024
#define READ 0
#define WRITE 1

int	main(void)
{
	int	fdA[2];
	int	fdB[2];
	pid_t	pid;
	char	buff[MAX_BUFF];
	int	count;

	count = 0;
	if (pipe(fdA) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	if (pipe(fdB) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	printf("\n");
	pid = fork();
	if (pid < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	if (pid > 0) // parent process
	{
		close(fdA[READ]);
		close(fdB[WRITE]);
		while (1)
		{
			sprintf(buff, "parent %d", count++);
			write(fdA[WRITE], buff, MAX_BUFF);
			memset(buff, 0, sizeof(buff));
			read(fdB[READ], buff, MAX_BUFF);
			printf("parent got messge : %s\n", buff);
			sleep(1);
		}
	}
	else // child process
	{
		close(fdA[WRITE]);
		close(fdB[READ]);
                count = 100000;
		while (1)
		{
			sprintf(buff, "child %d", count++);
			write(fdB[WRITE], buff, MAX_BUFF);
			memset(buff, 0, sizeof(buff));
			read(fdA[READ], buff, MAX_BUFF);
			printf("\tchild got messge : %s\n", buff);
			sleep(1);
		}
	}
	exit(0);
}
