#include<stdio.h>

int Factorial(int iNo)
{
    int iCnt = 0,iFact = 1;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt<=iNo; iCnt++)
    {
        iFact = iFact * iCnt;
    }

    return iFact;  
}