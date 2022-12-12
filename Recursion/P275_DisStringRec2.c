//Displaying the string recursively
#include<stdio.h>
void Display(char *str)
{
    if(*str != '\0')
    {
        printf("%c\n",*str);
        Display(str++); //error due to post increment of str (Display(100) Display(100) Display(100))
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