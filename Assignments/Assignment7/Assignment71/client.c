#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)();
    int iNo1 = 0, iNo2 = 0, iAns = 0;
    long int iAns1 = 0;

    ptr = dlopen("./library.so",RTLD_LAZY);   //runtime load lazy : if that so file is already on RAM then use that its lazy

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    /////////////////// Addition ///////////////////////////////////
    fptr = dlsym(ptr,"Addition");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function addition\n");
        return -1;
    } 

    printf("Enter first number\n");
    scanf("%d",&iNo1);

    printf("Enter second number\n");
    scanf("%d",&iNo2);

    iAns = fptr(iNo1, iNo2);

    printf("Addition is : %d\n",iAns);


    /////////////////// SUBSTRACTION ////////////////////////////////
    fptr = dlsym(ptr,"Substraction");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function substraction\n");
        return -1;
    } 

    iAns = fptr(iNo1, iNo2);

    printf("Substraction is : %d\n",iAns);

    /////////////////// MULTIPLICATION ////////////////////////////////
    fptr = dlsym(ptr,"Multiplication");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function substraction\n");
        return -1;
    } 

    iAns1 = fptr(iNo1, iNo2);

    printf("Multiplication is : %ld\n",iAns1);

    /////////////////// DIVISION ////////////////////////////////
    fptr = dlsym(ptr,"Division");   //dynamic link symbol : Display address

    if(fptr == NULL)
    {
        printf("Unable to load the address of function substraction\n");
        return -1;
    } 

    iAns = fptr(iNo1, iNo2);

    if(iAns == -1)
    {
        printf("Invalid inputs\n");
    }

    printf("Division is : %d\n",iAns);
    
    return 0;
}

// gcc -rdynamic -o Myexe client.c
//gcc -ldl -o Myexe client.c

//./Myexe