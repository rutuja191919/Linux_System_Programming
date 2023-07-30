
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int ret = 0;

    ret = nice(0);

    printf("Current Priority of the process is : %d\n",ret);

    ret = nice(-5);    //Increase the priority
    printf("Current Priority of the process is : %d\n",ret);

    return 0;
}