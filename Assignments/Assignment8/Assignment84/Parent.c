//execl() system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int Ret2 = 0, Ret3 = 0;
    int cpid = 0;
    int Exit_status = 0;

    Ret2 = fork();

    if(Ret2 == 0)  //Child
    {
        execl("./Process2","NULL",NULL);  
    }
    else   //Parent
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Process2 terminated having PID %d with exit status %d\n",cpid, Exit_status);
    }

    Ret3 = fork();

    if(Ret3 == 0)  //Child
    {
        execl("./Process3","NULL",NULL);  
    }
    else   //Parent
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Process3 terminated having PID %d with exit status %d\n",cpid, Exit_status);
    }

    
    return 0;
}