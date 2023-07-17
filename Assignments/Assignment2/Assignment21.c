#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    char Buffer[BLOCKSIZE];
    
    printf("Name_of_executable Name_of_the_file\n");

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,Ret);
    }

    return 0;
}