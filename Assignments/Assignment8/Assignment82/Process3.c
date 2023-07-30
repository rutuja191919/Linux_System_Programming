
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside process3 - PID of parent process(process2) is %d\n",getppid());
    
    return 0;
}