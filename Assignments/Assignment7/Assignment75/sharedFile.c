//code to share to another program

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "sharedFile.h"

void Display(char Fname[])
{
    struct stat sobj;
    int fd = 0;

    fd = open(Fname,O_RDONLY);
    fstat(fd,&sobj);

    printf("File name : %s\n",Fname);
    printf("File size is : %ld\n",sobj.st_size);
    printf("Number of links : %lu\n",sobj.st_nlink);    
    printf("Inode number : %lu\n",sobj.st_ino);
    printf("File system number : %lu\n",sobj.st_dev);
    printf("Number of blocks : %ld\n",sobj.st_blocks);
}

//Convert .c to .o
//gcc -c sharedFile.c -o sharedFile.o

//To create .a file : archive
//ar rcs sharedFile.a sharedFile.o

