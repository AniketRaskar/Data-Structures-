//after program 232 there is file handling taken and after this once on recursion from 265.c
#include<stdio.h>
//123
//output 3 2 1

void DisplayI(int no)  //I=Iteraative
{
    while(no != 0)
    {
        printf("%d\t",no%10);
        no = no/10;
    }
}

void DisplayR(int no)  //Recursion
{
    if(no != 0)
    {
        no = no/10;
        DisplayR(no);  //head recursion as func call is agodar
        printf("%d\t",no%10);  //In head recursion printf backtracking kartana execute hote
    }  
}
int main()
{
    DisplayI(123);  //Normal function
    printf("\n");
    DisplayR(123); //recursive func
    return 0;
}