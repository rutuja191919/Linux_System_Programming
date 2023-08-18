#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int key = 1234;
    char *ptr = NULL;

    printf("server is running\n");

    shmid = shmget(key, shmsize, IPC_CREAT | 0666);

    printf("Shared memory allocated successfully\n");

    ptr = shmat(shmid, NULL, 0);

    if(ptr != NULL)
    {
        printf("Shared memory attached successfully\n");
    }

    *ptr = 'H';
    ptr++;

    *ptr = 'E';
    ptr++;

    *ptr = 'L';
    ptr++;

    *ptr = 'L';
    ptr++;

    *ptr = 'O';
    ptr++;

    *ptr = '\0';
    ptr++;

    printf("Data written in shared memory successfully\n");

    shmdt(shmid);
    
    return 0;
}