#include<stdio.h>
#include "./sharedFile.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    Display(argv[1]);

    return 0;
}

//To compile : 
//gcc -static client.c -o Myexe sharedFile.a

//./Myexe