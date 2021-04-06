#include <unistd.h>
#include <stdio.h>

int	main()
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			printf("im child!!\n");
			sleep(1);
		}
	}
	else{
		printf("im parent!!\n");
		sleep(1);
	}
}