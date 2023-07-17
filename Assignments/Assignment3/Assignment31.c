#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define MAXSIZE 1024

int main(int argc, char *argv[])
{
    int fdsource = 0, fddest = 0, Ret = 0;
    char Buffer[MAXSIZE];


    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fdsource = open(argv[1], O_RDONLY);

    if(fdsource == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    fddest = creat(argv[2],0777);

    if(fddest == -1)
    {
        printf("Not able to create file\n");
        close(fdsource);
        return -1;
    }

    while((Ret = read(fdsource, Buffer, sizeof(Buffer))) != 0)
    {
        write(fddest,Buffer,Ret);
        memset(Buffer, 0, sizeof(Buffer));  //to avoid garbage
    }

    return 0;
}