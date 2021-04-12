#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 쓰레드 초기화

void* do_loop(void *data)
{
	int *a = (int *)data;
	for(int i=0; i<100000; i++)
	{
		//pthread_mutex_lock(&mutex); //잠금 생성
		//printf("loop1-%d : %d\n",i, *a);
		(*a)++;
		//pthread_mutex_unlock(&mutex); //잠금을 해제
		//usleep(1000 * 1000);
	}
	//*a = 0;
	return (NULL);
}

int	main()
{
	int		thr_id[2];
	pthread_t p_thread[2];
	int status;
	int a = 1;
	thr_id[0] = pthread_create(&p_thread[0], NULL, do_loop, (void *)&a);
	thr_id[1] = pthread_create(&p_thread[1], NULL, do_loop, (void *)&a);
	pthread_join(p_thread[0], NULL);
	pthread_join(p_thread[1], NULL);
	printf("%d\n", a);

	return (0);
}