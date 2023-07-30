#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<string.h>

extern char **environ;
int main()
{
    char **env = environ;

    printf("Environment of running process is : \n");

    for(;*env != NULL; env++)
    {
        if(strstr(*env,"LOGNAME") != 0)
        {
            printf("%s : \n",*env);
        }
        if(strstr(*env,"HOME") != 0)
        {
            printf("%s : \n",*env);
        }   
    }

    return 0;
}
