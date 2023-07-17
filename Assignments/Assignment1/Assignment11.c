#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid no of arguments\n");
        return -1;
    }

    printf("Usage : Name_of_executables Name_of_the_file_to_open\n");

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else
    {
        printf("File opened successfully with fd : %d",fd);
    }

    return 0;
}