//input 6
//output a  b   c   d   e   f
#include<stdio.h>

void Display(int iNo)
{
    int i=0;
    char ch = 'a';
    while(i<iNo)
    {
        printf("%c\t",ch);
        ch++;
        i++;
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