#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    char Buffer[20] = "\0";
    
    printf("Name_of_executable Name_of_the_file\n");

    fd = open(argv[1], O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    printf("Enter the string to write in the file\n");
    scanf("%s",Buffer);

    write(fd,Buffer,sizeof(Buffer));

    return 0;
    
}