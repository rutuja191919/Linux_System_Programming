#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>
#include<string.h>

#define MAXSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0, Ret = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char name[20], Buffer[MAXSIZE];

    if(argc != 2)
    {
        printf("invalid arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            printf("Information about file is : \n");
            printf("File Name  : %s\n",name);
            printf("File Size : %li\n",sobj.st_size);
            printf("Inode Number : %li\n",sobj.st_ino);
            printf("Number of blocks : %li\n",sobj.st_blocks);
            printf("Number of links : %li\n",sobj.st_nlink);

            fd = open(name, O_RDONLY);

            if(fd == -1)
            {
                printf("Unable to open the file in the directory\n");
                break;
            }

            printf("File contents are as follows: \n");
            while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
            {
                write(1,Buffer,Ret);
                memset(Buffer, 0, sizeof(Buffer));
            }
            printf("\n"); 
        }
    }

    close(fd);
    closedir(dp);
    
    return 0;
}