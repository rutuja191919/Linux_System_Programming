#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry;
    char DirName[20];
    struct stat sobj;
    char name[20];
    
    if(argc > 1)
    {
        printf("Invalid arguments\n");
        return -1;
    }
    
    printf("Enter the directory name\n");
    scanf("%s",DirName);

    dp = opendir(DirName);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("File names from the directory are : \n");
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        printf("%s\n",entry->d_name);
        stat(name, &sobj);

        printf("File Type : ");
        if(S_ISREG(sobj.st_mode))     
        {
            printf("It is regular file\n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("It is directory file\n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("It is symbolic link\n");
        }    
    }
    return 0; 
}