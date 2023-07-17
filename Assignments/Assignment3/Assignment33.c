//ctrt-x to ctrl-v
//rename is also used to rename the file from the same directory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char oldname[20];s
    char newname[20];

    if(argc != 3)
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
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
        sprintf(newname,"%s/%s",argv[2],entry->d_name);

        rename(oldname,newname);    
    }

    closedir(dp);
    return 0;
}
