//input 6
//output a  b   c   d   e   f
#include<stdio.h>

void Display(int iNo)
{
    static char ch = 'a';
    if(iNo > 0)
    {
        printf("%c\t",ch);
        ch++;
        iNo--;
        Display(iNo);
    }
}
int main()
{
    int Value =0;
    printf("Enter the number\n");
    scanf("%d",&Value);

    Display(Value);

    return 0;
}