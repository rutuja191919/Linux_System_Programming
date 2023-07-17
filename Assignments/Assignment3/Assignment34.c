#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/dir.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[20];
    struct stat sobj;
    int iCnt = 1;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
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
            if(sobj.st_size == 0)
            {
                remove(name);
            }
         }  
    }
    closedir(dp);
    return 0;
}