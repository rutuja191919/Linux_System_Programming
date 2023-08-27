#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[1024] = "";
    struct stat sobj;
 
    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }   

    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    } 

    stat(argv[1],&sobj);

    printf("%d",sobj.st_size);

    lseek(fd, 1024, sobj.st_size);
    //lseek(fd, 1024, SEEK_END);

    write(fd, Buffer, 1);
    
    return 0;
}
