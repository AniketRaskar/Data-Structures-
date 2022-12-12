//accept string from the user and find no of smallcase caracters from it
#include<stdio.h>

int CountSmall(char *str)
{
    int iCnt =0;
    while(*str != '\0')
    {
        if((*str >='a') && (*str <= 'z'))
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}
int main()
{
    char arr[20];
    int iRet =0;
    printf("Enter the string\n");
    scanf(" %[^'\n']s",arr);
    //gets(arr);   //also allowed
    iRet = CountSmall(arr);

    printf("Small characters are :%d\n",iRet);
    return 0;
}