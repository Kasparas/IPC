/*
 * The pipe.h library files consists of the two function read_pipe and write_pipe
 * A user must include "pipe.h" and write to these functions.
 */

#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

void pipe_read(char *FIFO_NAME, char *str);
void pipe_write(char *FIFO_NAME, void *VAR, int b, char *word);

#endif

