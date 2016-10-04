#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
 
void *thread_function (void *arg);
void *thread_function1 (void *arg);
 int a = 0;
 int i;
int main()
{
//Pipe stuff1
   pthread_t a_thread;
      pthread_create (&a_thread, NULL, thread_function1, NULL);
	  pthread_create (&a_thread, NULL, thread_function, NULL);
	sleep(1);
for (i = 0; i<20; i++){
printf("%d ",i);
  
}
exit(0);
}
 
 
void *thread_function1 (void *arg)
{

FILE *file; 
	file = fopen("saved_data.txt","a+"); // 
char *FIFO_NAME = "GUN3";
char s[350];

	//Conversion from str to double + str
	char str[350] = "\n";
    char *ptr[350];
    double ret;	
  printf ("1 Thread running\n");
  pipe_read(FIFO_NAME, s);
  	strcpy(str, s);
    ret = strtod(str, ptr);
  fprintf(file,"Pipe name is |%s|\n", FIFO_NAME);
    fprintf(file,"The data is |%lf|\n", ret);
   fprintf(file,"String part is |%s|\n", *ptr);
    fclose(file); /*done!*/ 
  pthread_exit("thread exiting");
}

void *thread_function (void *arg)
{
 FILE *file; 
	file = fopen("saved_data.txt","a+"); //
char *FIFO_NAME = "GUN4";
char s[350];

	//Conversion from str to double + str
	char str[350] = "\n";
    char *ptr[350];
    double ret;	
  printf ("2 Thread running\n");
  pipe_read(FIFO_NAME, s);
  	strcpy(str, s);
    ret = strtod(str, ptr);
  fprintf(file,"Pipe name is |%s|\n", FIFO_NAME);
    fprintf(file,"The data is |%lf|\n", ret);
   fprintf(file,"String part is |%s|\n", *ptr);
  	  fclose(file); /*done!*/ 
  pthread_exit("thread exiting");
}