#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define SIGNALS_TO_PERFORM 100000

int signals_performed = 0;
struct timeval start,end;


void handle_sigfpe(int signum)
{
	signals_performed++;

	if(signals_performed == SIGNALS_TO_PERFORM)
	{
		gettimeofday(&end,NULL);
		double total_time = end.tv_usec - start.tv_usec;
		printf("Syscalls Performed: %d\n",signals_performed);
		printf("Total Elapsed Time: %f ms\n",total_time);
		printf("Average Time Per Signal: %f ms\n",total_time / SIGNALS_TO_PERFORM);
		exit(1);
	}

}

int main(int argc, char **argv)
{

	int x = 0, y = 0,z;
	gettimeofday(&start,NULL);

	signal(SIGFPE, handle_sigfpe);
	z = x / y; 

	return 1;
}