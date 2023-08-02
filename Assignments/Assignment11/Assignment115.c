#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
    int fd = 0, i = 0;
    char Buffer[512];
    char Data[40];
    int iCnt = 0, iRet = 0;

    fd = open("Data.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file");
        return -1;
    }

    while((iRet = (read(fd,Buffer,sizeof(Buffer)))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of capital characters are : %d\n", iCnt);
    close(fd);
    pthread_exit(NULL); //Thread should killed explicitely
}

void * ThreadProc2(void *ptr)
{
    int fd = 0, i = 0;
    char Buffer[512];
    char Data[40];
    int iCnt = 0, iRet = 0;

    fd = open("Data.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file");
        return -1;
    }

    while((iRet = (read(fd,Buffer,sizeof(Buffer)))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of small characters are : %d\n", iCnt);
    close(fd);
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

    pthread_exit(NULL);  

    return 0;
}