#include <stdio.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>

#define SEM_ID "/sem_id"

sem_t	*sem;
int		value = 0;

void	*thread_loop(void *data)
{
	sem_wait(sem);
	for(int i=0; i<100000; i++)
		value++;
	sem_post(sem);
	return (NULL);
}

int		main()
{
	sem = sem_open(SEM_ID, O_CREAT, 0644, 1);
	pthread_t pthread[2];
	pthread_create(&pthread[0], NULL, thread_loop, NULL);
	pthread_create(&pthread[1], NULL, thread_loop, NULL);
	pthread_join(pthread[0], NULL);
	pthread_join(pthread[1], NULL);
	printf("value : %d", value);
	sem_unlink(SEM_ID);
	sem_close(sem);
	
}