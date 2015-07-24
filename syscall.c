#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void print_usage(char *progname)
{
	printf("Usage: %s <syscall or usermode> \n", progname);
	exit(1);
}

int main (int argc, char *argv[])
{
	unsigned int TEN_MILLION = 10000000;
	unsigned int i = 0;
	
	if (argc < 2)
	{
		print_usage(argv[0]);
	}
	
	if (strcmp(argv[1], "syscall") == 0)
	{
		for (i = 0; i < TEN_MILLION; i++)
		{
			getppid();
		}
	}
	else if (strcmp(argv[1], "usermode") == 0)
	{
		for (i = 0; i < TEN_MILLION; i++)
		{
			rand() + rand();
		}
	}
	else
	{
		print_usage(argv[0]);
	}
	exit(0);
}
