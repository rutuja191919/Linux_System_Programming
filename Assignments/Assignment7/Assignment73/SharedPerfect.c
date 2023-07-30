#include<stdio.h>
#include<stdbool.h>

bool ChkPerfect(int iNo)
{
    int iCnt = 0, iSum = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = (iNo/2); ((iCnt >= 1) && (iSum <= iNo)); iCnt--)
    {
        if(iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }

        if(iSum > iNo)  //optimization
        {
            break;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
