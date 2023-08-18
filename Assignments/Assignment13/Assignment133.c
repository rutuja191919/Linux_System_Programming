#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signo)
{
    printf("Received signal is : %d\n",signo);
}

int main(int argc, char *argv[])
{
    int iRet = 0;
 
    iRet = fork();

    if(iRet == 0)
    {
        //Child process 
        sleep(5);
        kill(getppid(), atoi(argv[1]));
    }
    else
    {
        signal(atoi(argv[1]), sig_handler);

        int x;
        printf("what is the result of 3 x 5:");
        scanf("%d",&x);
        if(x = 15)
        {
            printf("Right!\n");
        }
        else
        {
            printf("Wrong!\n");
        }

        wait(NULL);
    }
    
    return 0;
}