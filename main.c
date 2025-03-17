#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	handle_signal(int id)
{
	printf("signal recu");
	fflush(stdout);
}

int	main()
{
   	printf("PID du processus d'attente : %d\n", getpid());
	printf("J'attends que tu emettes un signal\n");
	fflush(stdout);
	signal(SIGUSR1, handle_signal);

	while (1)
	{
		pause();
	}

	return (0);
}