#include<stdio.h>
#include "sharedFile.h"

int Addition(int iNo1, int iNo2)
{
    return iNo1 + iNo2;
}

int Substraction(int iNo1, int iNo2)
{
    return iNo1 - iNo2;
}

int Multiplication(int iNo1, int iNo2)
{
    return iNo1 * iNo2;
}

int Division(int iNo1, int iNo2)
{
    if(iNo2 == 0)
    {
        return -1;
    }

    return iNo1 / iNo2;
}
