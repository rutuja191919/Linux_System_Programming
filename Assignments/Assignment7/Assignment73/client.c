#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)();
    int iNo = 0;
    bool flag = false;

    printf("Enter then number\n");
    scanf("%d",&iNo);

    ptr = dlopen("./libraryPrime.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"ChkPrime");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    flag = fptr(iNo);

    if(flag == true)
    {
        printf("Number is prime\n");
    }
    else
    {
        printf("Number is not prime\n");
    }

    ptr = dlopen("./libraryPerfect.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"ChkPerfect");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    flag = fptr(iNo);

    if(flag == true)
    {
        printf("Number is perfect\n");
    }
    else
    {
        printf("Number is not perfect\n");
    }

    return 0;
}

// gcc -rdynamic -o Myexe client.c
//gcc -ldl -o Myexe client.c

//./Myexe