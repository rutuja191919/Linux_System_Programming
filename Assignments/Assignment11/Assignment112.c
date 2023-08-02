#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    printf("inside thread 1\n");
    pthread_exit(NULL); 
}

void * ThreadProc2(void *ptr)
{
    printf("inside thread 2\n");
    pthread_exit(NULL); 
}

int main()
{
    pthread_t TID[2];   
    pthread_attr_t TARR[2];  
    int ret = 0, i = 0, reta = 0;
    void (*p[2]) (void *) = {ThreadProc1, ThreadProc2};

    for(i = 0; i < 2 ; i++)
    {
        ret = pthread_attr_init(&TARR[i]);
        ret = pthread_attr_setdetachstate(&TARR[i],PTHREAD_CREATE_DETACHED);

        if(ret != 0)
        {
            printf("Unable to set/initialize attribute to the thread\n");
            return -1;
        }

        ret = pthread_create(&TID[i],       
                             &TARR[i],       
                             p[i], 
                             NULL);     

        if(ret != 0)
        {
            printf("Unable to create thread 1\n");
            return -1;
        }

        printf("Thread1 is created with ID : %d\n",TID[i]);

        ret = pthread_attr_getdetachstate(&TARR[i],&reta);
        if(reta != 0)
        {
            printf("Thread in detached state\n");
        }
    }

    for(i = 0; i < 2; i++)
    {
        pthread_join(TID[0], NULL);
    }

    printf("End of main thread\n");

    pthread_exit(NULL);  //Thread killed explicitely

    return 0;
}