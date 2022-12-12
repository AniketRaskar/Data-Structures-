//input 6
//output a  b   c   d   e   f
#include<stdio.h>

void Display(int iNo)
{
    int i=0;
    char ch = 'a';
    for(i=0;i<iNo;i++)
    {
        printf("%c\t",ch);
        ch++;
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