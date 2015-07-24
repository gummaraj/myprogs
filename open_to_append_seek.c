#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FNAME "/home/vagrant/src/sysprog/append_file"

int main (int argc, char *argv[])
{
	int fd = 0;
	off_t curr_offset;
	
	fd = open(FNAME, O_RDWR | O_APPEND);
	if (fd < 0) 
	{
		perror("open failed");
		exit(1);
	}
	curr_offset = lseek(fd, 0, SEEK_CUR);
	printf("Current Offset at (%lld)\n", (long long)curr_offset);
	write(fd, "AAA_HI_THERE____\n", 17);
	curr_offset = lseek(fd, 0, SEEK_SET);
	printf("Current Offset at (%lld)\n", (long long)curr_offset);
	write(fd, "BBB_HI_THERE____\n", 17);
	close(fd);
}
