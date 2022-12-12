//Displaying the string recursively
#include<stdio.h>
void Display(char *str)
{
    if(*str != '\0')
    {
        printf("%c\n",*str);
        Display(++str); //pre increment  
        //tail recursion
    }
}
int main()
{
    char Arr[20];

    printf("Enter the string\n");
    scanf("%[^'\n']s",Arr);

    Display(Arr);
    return 0;
}