#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int iRet = 0;

    iRet = sched_yield();  //The sched_yield() function allows a thread to give up control of a processor so that another thread can have the opportunity to run.

    if(iRet == 0)
    {
        printf("Processor yield successfully\n");
    }

    return 0;
}