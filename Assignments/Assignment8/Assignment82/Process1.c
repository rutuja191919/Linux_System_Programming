//execl() system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int Ret = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret = fork();

    if(Ret == 0)  //Child
    {
        execl("./Process2","NULL",NULL);  
    }
    else   //Parent
    {
        printf("Process1 is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Process2 terminated having PID %d with exit status %d\n",cpid, Exit_status);
    }
    
    return 0;
}