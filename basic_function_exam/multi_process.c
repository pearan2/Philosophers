#include <stdio.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define SEMID "/semid"

int		child_num = 0;
sem_t	*sem;

void	say_child(void)
{
	sem_wait(sem);
	for(int i=0; i<1000; i++)
	{
		printf("im child %d !\n", child_num);
	}
	sem_post(sem);
	exit(0);
}

int	main(int ac, char **av)
{
	int num = 3;
	int pid[num];

	sem_unlink(SEMID);
	sem = sem_open(SEMID, O_CREAT | O_EXCL, 0644, 1);
	
	for (int i=0; i<num; i++)
	{
		child_num++;
		pid[i] = fork();
		if (pid[i] == 0)
			say_child();
	}
	sleep(2);
	printf("parent end\n");
}