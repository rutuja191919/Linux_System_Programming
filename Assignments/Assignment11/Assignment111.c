#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("Inside thread 1\n");
    pthread_exit(NULL); //Thread should killed explicitely
}

void * ThreadProc2(void *ptr)
{
    printf("Inside thread 2\n");
    pthread_exit(NULL); //Thread should killed explicitely
}

void * ThreadProc3(void *ptr)
{
    printf("Inside thread 3\n");
    pthread_exit(NULL); //Thread should killed explicitely
}

void * ThreadProc4(void *ptr)
{
    printf("Inside thread 4\n");
    pthread_exit(NULL); //Thread should killed explicitely
}

int main()
{
    pthread_t TID[4];   
    int ret = 0, i = 0;
    void (*p[4]) (void *) = {ThreadProc1, ThreadProc2, ThreadProc3, ThreadProc4};

    for(i = 0; i < 4 ; i++)
    {
        ret = pthread_create(&TID[i],       
                         NULL,       
                         p[i], 
                         NULL);   

        if(ret != 0)
        {
            printf("Unable to create thread 1\n");
            return -1;
        }  

        printf("Thread%d is created with ID : %d\n",i,TID[i]);

    }
    
    for(i = 0; i < 4; i++)
    {
    	pthread_join(TID[i], NULL);
    }

    printf("End of main thread\n");

    pthread_exit(NULL);  //Thread killed explicitely

    return 0;
}
