#include <stdio.h>
//factorial of numbers
//4
//4 * 3 * 2 * 1    24

int FactorialI(int iNo)
{
    auto int iFact =1;
    while(iNo > 0)
    {
        iFact = iFact * iNo;
        iNo--;
    }
    return iFact;
}
int main()
{
    int iValue =0;
    int iRet =0;
    printf("Enter the value\n");
    scanf("%d",&iValue);

    iRet=FactorialI(iValue);

    printf("Factorial is : %d\n",iRet);

    return 0;
}