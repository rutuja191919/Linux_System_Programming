#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int key = 1234;
    char *ptr = NULL;

    printf("Client application running\n");

    shmid = shmget(key, shmsize, 0666);

    ptr = shmat(shmid, NULL, 0);

    if(ptr != NULL)
    {
        printf("Shared memory attached successfully\n");
    }

    printf("Data from shared memory\n");

    while(*ptr != '\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n");

    shmdt(shmid);
    
    return 0;
}