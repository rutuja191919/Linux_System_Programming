#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    char Arr[20];

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);
    
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    ret = read(fd,Arr,20);

    printf("The data from file is \n");
    write(1,Arr,ret);

    return 0;
}
