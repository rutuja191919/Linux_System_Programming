#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0, iNo3 = 0;
    int iAns = 0;

    scanf("%d", &iNo1);
    scanf("%d", &iNo2);
    scanf("%d", &iNo3);

    iAns = iNo1 * iNo2 * iNo3;

    printf("Multiplication of nos is : %d",iAns);

    return 0;
}