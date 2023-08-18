#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;
    char Buffer[100];
    char *path = "./mypipe";

    printf("Client is running and reading the data from named pipe....\n");
    fd = open(path, O_RDONLY);

    read(fd,Buffer,11);

    printf("Data from pipe is : %s\n",Buffer);

    close(fd);

    return 0;
}