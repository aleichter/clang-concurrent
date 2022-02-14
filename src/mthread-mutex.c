#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
  
void *myThreadFun()
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
   
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    printf("During Thread\n");
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}