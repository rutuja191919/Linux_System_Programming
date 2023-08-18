#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int FD[2];
    int iRet = 0;
    char Arr[] = "Hello World";
    char Buffer[512] = {};

    pipe(FD);

    iRet = fork();

    if(iRet == 0)
    {
        printf("Child process for reading\n");
        close(FD[1]);
        read(FD[0], Buffer, sizeof(Buffer));
        printf("Data from pipe is : %s\n", Buffer);
    }
    else
    {
        printf("Parrent process for writing\n");
        close(FD[0]);
        write(FD[1],Arr,strlen(Arr));
    }
    
    return 0;
}