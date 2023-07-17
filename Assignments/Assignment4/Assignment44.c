#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fdnew = 0;
    DIR *dp = NULL;
    char Buffer[20], name[20];
    struct stat sobj;
    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fdnew = creat("Demo.txt",0777);

    if(fdnew == -1)
    {
        printf("Unable to create the file\n");
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
        int Ret = 0, fd = 0;
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fd = open(name, O_RDONLY);

            if(fd == -1)
            {
                printf("Unable to open the file in the directory\n");
                break;
            }

            Ret = read(fd, Buffer, 10);
            write(fdnew, Buffer, Ret);
            write(fdnew,"\n",1);
            memset(Buffer, 0, sizeof(Buffer));

            close(fd);
        }
    }

    close(fdnew);
    closedir(dp);

    return 0;
}
