#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Inside Thread\n");
    printf("Thread ID of the current thread is : %d\n",pthread_self());
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    int Ret = 0;

    Ret = pthread_create(&tid,
                        NULL,
                        ThreadProc,
                        NULL);

    if(Ret != 0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }

    printf("Thread is created with the ID : %d\n",tid);

    pthread_join(tid,NULL);

    printf("End of main\n");

    return 0;
}