//accept no from user and write the addition of digits in it
#include<stdio.h>

int AdditionDigits(int iNo)
{
    int iDigit =0;
    static int iSum =0;
    if(iNo != 0)
    {
        iDigit = iNo%10;
        iSum = iSum + iDigit;
        iNo = iNo /10;
        AdditionDigits(iNo);
    }
    return iSum;
}
int main()
{
    int iValue =0;
    int iRet =0;
    printf("Enter the number\n");
    scanf("%d",&iValue);

    iRet = AdditionDigits(iValue);
    printf("Addition of digits in the entered number %d is %d",iValue,iRet);
    return 0;
}