#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    long int iMax = 0;
    DIR *dp = NULL;
    struct dirent *entry;
    char DirName[20];
    struct stat sobj;
    char name[20];
    char largest[20];

    
    printf("Enter the directory name\n");
    scanf("%s",DirName);

    dp = opendir(DirName);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name, &sobj);

        if(iMax < sobj.st_size)
        {
            iMax = sobj.st_size;
            strcpy(largest, name);
        }        
    }

    printf("Name of the largest file : %s with the size : %li \n",largest,iMax);
    closedir(dp);

    return 0; 
}