#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#define SYSCALLS_TO_PERFORM 100000
int main(int argc, char ** argv)
{
	int i = 0;
	struct timeval start,end;
	double total_time = 0.0;

	gettimeofday(&start,NULL);

	for (i = 0; i < SYSCALLS_TO_PERFORM; i ++) {
		getpid();
	}

	gettimeofday(&end,NULL);
	if(end.tv_usec == 0 || start.tv_usec == 0) {
		printf("gettimeofday failed\n");
		exit(-1);
	}
	total_time = (end.tv_usec - start.tv_usec);


	printf("Syscalls Performed: %d\n",i);
	printf("Total Elapsed Time: %f ms\n",total_time);
	printf("Average Time Per Syscall: %f ms\n",total_time / SYSCALLS_TO_PERFORM);

	return 1;
}