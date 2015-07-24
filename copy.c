#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
	int inputFd;
	int outputFd;
	int openFlags;
	ssize_t numRead;
	char buf[BUF_SIZE];

	inputFd = open(argv[1], O_RDONLY);
	if (inputFd < 0)
	{
		perror("input file open");
		exit(1);
	}
	outputFd = open(argv[2], (O_CREAT | O_WRONLY | O_TRUNC), (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH));
	if (outputFd < 0)
	{
		perror("output file open");
		exit(1);
	}
	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
	{
		if ((write(outputFd, buf, numRead)) != numRead)
		{
			perror("fatal: write error");
			exit(2);
		}
	}
	
	if (close(inputFd) < 0)
		perror("close inputFd");
	if (close(outputFd) < 0)
		perror("close outputFd");
	exit(0);
}

