
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int ret = 0;

    ret = nice(0);

    printf("Current Priority of the process is : %d\n",ret);

    return 0;
}