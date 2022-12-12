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
        printf("%d\t",no%10);
        no = no/10;
        DisplayR(no);  //tail recursion as fun call is lastly
    }  
}
int main()
{
    //DisplayI(123);  //Normal function

    DisplayR(123); //recursive func
    return 0;
}