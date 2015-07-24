#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define FNAME "/home/vagrant/src/sysprog/largefile"

int main (int argc, char *argv[])
{
	int fd = 0;
	off_t curr_offset;
	off_t new_offset;
	char buf[512] = {'\0'};

	fd = open(FNAME, O_CREAT|O_RDWR, S_I);
	if (fd < 0)
	{
		perror("file open failed");
		exit(1);
	}
	printf("fd = (%d), pid(%u)\n", fd, getpid());
	curr_offset = lseek(fd, 0, SEEK_CUR);
	printf("current offset = (%lld)\n", (long long)curr_offset);
	sleep((unsigned int)strtol(argv[1], NULL, 10));
	new_offset = (off_t)strtol(argv[2], NULL, 10);
	curr_offset = lseek(fd, new_offset, SEEK_CUR);
	sprintf(buf, "hi there from PID [ %u ]\n", (unsigned int)getpid());
	write(fd, buf, strlen(buf));
	printf("setting new offset to %d\n", (unsigned int)strtol(argv[2], NULL, 10));
	printf("sleeping\n");
	sleep((unsigned int)strtol(argv[1], NULL, 10));
	close(fd);
}

