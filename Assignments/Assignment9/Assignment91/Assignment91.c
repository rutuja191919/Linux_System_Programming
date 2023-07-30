#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int ret,status;

    ret = fork();
    if(ret == 0)
    {
        execl("./Process","NULL",NULL);

    }

    wait(&status);
    
    return 0;
}