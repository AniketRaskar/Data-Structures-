#include<stdio.h>
//Display * * * * by recurssion

void DisplayI()  //I=Iteraative
{
    auto int iCnt=0;
    while(iCnt < 4)
    {
        printf("*\t");
        iCnt++;
    }
}

void DisplayR()  //Recursion
{
    static int iCnt=0;
    if(iCnt < 4)
    {
        printf("*\t");
        iCnt++;
        DisplayR();  //recurssive call
    }  
}
int main()
{
    //DisplayI();  //Normal function

    DisplayR(); //recursive func
    return 0;
}