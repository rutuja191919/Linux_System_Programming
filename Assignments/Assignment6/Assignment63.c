#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/dir.h>\

int main(int argc, char *argv[])
{
    int fd = 0;
    char name[20];

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    sprintf(name,"%s/%s",argv[1], argv[2]);

    fd = creat(name,0777);

    if(fd == -1)
    {
        printf("Unable to create the file in the directory\n");
        return -1;
    }

    close(fd);
    return 0;
}