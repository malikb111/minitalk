#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	pid_t	pid;

	pid = atoi(av[1]);
	kill(pid, SIGUSR1);
	return (0);
}