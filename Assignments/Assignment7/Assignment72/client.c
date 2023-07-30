#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    int (*fptr)();
    bool flag = false;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    ptr = dlopen("./library.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Compare");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    flag = fptr(argv[1], argv[2]);

    if(flag == true)
    {
        printf("Files are same\n");
    }
    else
    {
        printf("Files are different\n");
    }

    return 0;
}

// gcc -rdynamic -o Myexe client.c
//gcc -ldl -o Myexe client.c

//./Myexe