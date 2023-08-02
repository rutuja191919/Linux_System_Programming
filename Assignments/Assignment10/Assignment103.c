#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    printf("Inside Thread\n");
    printf("Value received as a parameter is : %d\n", (int)ptr);
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    int Ret = 0, no = 50;

    Ret = pthread_create(&tid,
                        NULL,
                        ThreadProc,
                        (int *)no);

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