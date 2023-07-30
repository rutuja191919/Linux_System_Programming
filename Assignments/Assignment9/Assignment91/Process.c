#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    DIR *dp = NULL;
    char Dirname[40], name[50];
    struct dirent *entry = NULL;
    int fd = 0, i = 0, fd1 = 0;
    struct stat sobj;
    int iCnt = 0, iRet = 0;

    strcpy(Dirname,"/home/rutuja/Desktop");

    dp = opendir(Dirname);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    fd = creat("demo.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s\n",Dirname,entry->d_name);

        fd = open("demo.txt",O_WRONLY | O_APPEND);
        write(fd, name, sizeof(name));
    }

    close(fd);   
    return 0;
}