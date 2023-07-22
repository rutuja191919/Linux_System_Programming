#include<stdio.h>
#include<dlfcn.h>
#include "sharedFile.h"

int Nest()
{
    void *ptr = NULL;
    int (*fptr)();
    int iNo1 = 0, iNo2 = 0;

    ptr = dlopen("./SubstractionS.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Substraction");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    printf("Enter first number\n");
    scanf("%d",&iNo1);

    printf("Enter second number\n");
    scanf("%d",&iNo2);

    return fptr(iNo1,iNo2);
}

//To create .o file
//gcc -c -fPic sharedFile.c

//To create .so file
//gcc -shared -o library.so sharedFile.o