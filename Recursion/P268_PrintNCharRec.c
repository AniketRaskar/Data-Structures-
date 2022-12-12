//input 6
//output a  b   c   d   e   f
#include<stdio.h>

void Display(int iNo)
{
    static int i=0;
    static char ch = 'a';
    if(i<iNo)
    {
        printf("%c\t",ch);
        ch++;
        i++;
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