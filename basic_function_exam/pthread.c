#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*thread(void *arg)
{
	printf("%s\n", (char *)arg);
	return (NULL);
}

int		main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread, "Hello!!"); // 이 시점에서 메인스레드와 피어스레드가 돌고있다.
	pthread_join(tid,NULL);  //메인스레드가 피어스레드의 종료를 기다린다.
	pthread_detach(tid); // thread 를 커널에서 분리시킴. 분리된 스레드는 수행을 종료시키고 자원을 회수한다.
	exit(0);
}

// 컴파일 할 때 -lpthread 넣어야
// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

//      새로운 스레드를 스레드 속성 attr에 따라 생성한다.
//      스레드 속성 객체 attr이 NULL이라면 기본 스레드 속성으로 스레드를 생성한다.
//      스레드가 성공적으로 생성되면 생성된 스레드 ID는 thread에 저장된다.
//      생성된 스레드는 start_routine을 arg 인자를 사용하여 실행한다.
//      start_routine이 반환되면 내부적으로 pthread_exit() 함수가 호출되어 스레드가 종료된다.
     
// int pthread_join(pthread_t thread, void **value_ptr);
//      스레드 종료를 대기한다. 대기하는 스레드가 종료되면, value_ptr 인자의 값은 pthread_exit() 함수가 전달한 종료 값을 얻게된다.