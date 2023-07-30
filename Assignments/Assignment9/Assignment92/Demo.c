#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0, i = 0, fd1 = 0;
    char Buffer[512];
    char Data[80];
    int iCnt = 0, iRet = 0;

    fd = open("Demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file");
        return -1;
    }

    while((iRet = (read(fd,Buffer,sizeof(Buffer)))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    fd1 = open("Count.txt",O_WRONLY | O_APPEND);

    sprintf(Data,"%s%d\n","No of capital characters from Demo.txt are: ",iCnt);

    write(fd1, Data, sizeof(Data));

    printf("Number of capital characters are : %d\n", iCnt);
    
    close(fd1);
    close(fd);
    
    return 0;
}