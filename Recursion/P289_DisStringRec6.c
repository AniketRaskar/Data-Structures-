//Displaying the string recursively
//here data gets displyed while back traking of the stack
#include<stdio.h>
void Display(char *str)
{
    if(*str != '\0')
    {
        Display(str+1); //head recursion
        printf("%s\n",str);  //%s is uded to display the string till \0
        
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