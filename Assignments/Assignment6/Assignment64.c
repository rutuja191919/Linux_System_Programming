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
            if(sobj.st_size > 100)
            {
                remove(name);
            }
        }
    }

    closedir(dp);
    
    return 0;
}