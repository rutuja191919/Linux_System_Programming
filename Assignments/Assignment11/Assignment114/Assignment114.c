#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int counter = 0;
pthread_mutex_t lock;

void * ThreadProc(void *ptr)
{
    pthread_mutex_lock(&lock);
    counter++;
    printf("Inside thread : %d\n",counter);
    printf("Thread %d has finished\n", counter);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL); 
}

int main()
{ 
    pthread_t TID[2];  
    int ret = 0, i = 0;

    if(pthread_mutex_init(&lock,NULL) != 0)
    {
        printf("Mutex init failed\n");
        return -1;
    }
    
    for(i = 0; i < 2 ; i++)
    {
        ret = pthread_create(&TID[i],       
                             NULL,       
                             ThreadProc, 
                             NULL);     

        if(ret != 0)
        {

            printf("Unable to create thread 1\n");
            return -1;
        }

        printf("Thread%d is created with ID : %d\n",i+1,TID[i]);
    }
    
    for(i = 0; i < 2; i++)
    {
        pthread_join(TID[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    
    printf("End of main thread\n");

    pthread_exit(NULL);  //Thread killed explicitely

    return 0;
}