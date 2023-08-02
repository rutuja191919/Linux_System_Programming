#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int counter = 0;
void * ThreadProc(void *ptr)
{
    counter++;
    printf("Inside thread : %d\n",counter);
    printf("Thread %d has finished\n", counter);
    pthread_exit(NULL); 
}

int main()
{ 
    pthread_t TID[2];  
    int ret = 0, i = 0;

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

    printf("End of main thread\n");

    pthread_exit(NULL);  //Thread killed explicitely

    return 0;
}