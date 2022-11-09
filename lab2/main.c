#include <stdio.h>
#include <stdlib.h>

int toNumber(char string[])
{
    long int number = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        int x = string[i] - '0';
        if (x < 0 || x > 9)
            return 0;
        number = number * 10 + x;
    }
    return number;
}

int toNumberModify(char string[])
{
    long int number = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        int x = string[i] - '0';
        if (x >= 0 && x <= 9)
            number = number * 10 + x;
    }
    return number;
}

int calc(char string[])
{
   
    
}
int main(void)
{
    calc("12*789=");

    

    // char *expression[] = {"2+x=5", "x+2=5", "2+x=5", "x-5=2", "5-x=2", "x=5*2", "x*5=10", "9*9=x", "x=10/3", "x/2=5", "10/x=5"};

    // int len = sizeof(expression) / sizeof(char *);

    // for (int i = 0; i < len; i++)
    //     printf("%s x=%d\n", expression[i], Calc(expression[i]));
}