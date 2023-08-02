#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

// void * ________(void * _____)
// {}

void * ThreadProc1(void *ptr)
{
    int i = 0;
     
    for(i = 1; i<=500; i++)
    {
        printf("%d\n",i);
    }
    pthread_exit(NULL); //Thread should killed explicitely
}

void * ThreadProc2(void *ptr)
{
    int i = 0;
     
    for(i = 500; i>=1; i--)
    {
        printf("%d\n",i);
    }
    pthread_exit(NULL); //Thread should killed explicitely
}

int main()
{
    pthread_t TID1, TID2;   
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,       
                         NULL,       
                         ThreadProc1, 
                         NULL);     

    if(ret1 != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }

    printf("Thread1 is created with ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,       
                         NULL,       
                         ThreadProc2, 
                         NULL);     

    
    if(ret2 != 0)
    {
        printf("Unable to create thread 2\n");
        return -1;
    }

    printf("Thread2 is created with ID : %d\n",TID2);
    
    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);  

    printf("End of main thread\n");

    pthread_exit(NULL);  //Thread killed explicitely

    return 0;
}