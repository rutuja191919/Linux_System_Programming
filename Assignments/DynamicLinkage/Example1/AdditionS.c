#include<stdio.h>
#include "sharedFile.h"

int Addition(int iNo1, int iNo2)
{
    return iNo1 + iNo2;
}

//To create .o file
//gcc -c -fPic sharedFile.c

//To create .so file
//gcc -shared -o library.so sharedFile.o