#include <unistd.h>
#include <stdio.h>

int	main()
{
	int pid;
	int a = 5;

	pid = fork();
	if (pid == 0)
	{
		a += 5;
		printf("hi im child!! value >> %d\n", a);
		return (0);
	}
	sleep(1);
	printf("hi im child!! value >> %d\n", a);
}