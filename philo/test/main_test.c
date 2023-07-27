#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void *func1(void *arg)
{
	for (int i = 0; i < 10; i++)
		fprintf(stderr, "\33[91m thread 1: %d\033[0m\n", i);
	pthread_exit(NULL);
}

void *func2(void *arg)
{
	for (int i = 0; i < 10; i++)
		fprintf(stderr, "\33[95m thread 2: %d\033[0m\n", i);
	pthread_exit(NULL);
}




int main (void)
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, func1, NULL);
	pthread_create(&t2, NULL, func2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return(0);
}