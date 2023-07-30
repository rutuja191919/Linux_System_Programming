#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>

int Nest()
{
    void *ptr = NULL;
    int (*fptr)();
    int iNo = 0;

    printf("Enter the number\n");
    scanf("%d",&iNo);

    ptr = dlopen("./libraryFact.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Factorial");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    return fptr(iNo);
}
