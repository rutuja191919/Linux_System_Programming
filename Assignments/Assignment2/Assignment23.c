#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry;
    char DirName[20];
    
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
        printf("%s\n",entry->d_name);
    }

    return 0; 
}