#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)();
    int iAns = 0;

    ptr = dlopen("./Shared.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Nest");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    iAns = fptr();

    printf("Factorial of the number is : %d\n",iAns);

    return 0;
}

// gcc -rdynamic -o Myexe client.c
//gcc -ldl -o Myexe client.c

//./Myexe