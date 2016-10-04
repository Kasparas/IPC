#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "pipe.h"

void pipe_read(char *FIFO_NAME,char *str)
{
	int num, fd;
	mkfifo(FIFO_NAME, 0666); // Make node, fifo mode, set access permissions so everything gets to rw-

	fd = open(FIFO_NAME, O_RDONLY ); // Open fifo, read only

	if ((num = read(fd, str, 350)) == -1) // Reads here and checks for error
	{
		perror("read");
	}
}

void pipe_write(char *FIFO_NAME, void *VAR, int b, char *word)
{
	char str[350] = "0"; // Buffer that is initially set to 0.

	if(b == 1) // If integer
	{
		sprintf(str, "%d %s", *(int*)VAR, word); // Recieves int and a string, and puts it into 'str'
	}

	else if(b == 2) // If double
	{
		sprintf(str, "%f %s", *(double*)VAR, word); // Recieves double and a string, and puts it into 'str'
	}

	int num, fd;

	mkfifo(FIFO_NAME, 0666); // Make node, fifo mode, set access permissions so everything gets to rw-

	fd = open(FIFO_NAME, O_WRONLY | O_NONBLOCK );

	if ((num = write(fd, str, 350)) == -1) // Writes here and checks for error
	{
		perror("writer");
	}
}
