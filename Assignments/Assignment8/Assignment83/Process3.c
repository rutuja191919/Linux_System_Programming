
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside process3 - PID of parent process is %d\n",getppid());
    
    return 0;
}