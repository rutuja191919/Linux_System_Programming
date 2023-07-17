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
    int fd = 0, fdnew = 0, Ret = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char name[20], Buffer[MAXSIZE];

    if(argc != 2)
    {
        printf("invalid arguments\n");
        return -1;
    }

    fdnew = creat("AllCombine.txt",0777);

    if(dp == -1)
    {
        printf("Unable to create the file");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        close(fdnew);
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fd = open(name, O_RDONLY);

            if(fd == -1)
            {
                printf("Unable to open the file in the directory\n");
                break;
            }

            while((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
            {
                write(fdnew,Buffer,Ret);
                memset(Buffer, 0, sizeof(Buffer));
            }
        }
    }

    close(fdnew);
    close(fd);
    closedir(dp);
    
    return 0;
}