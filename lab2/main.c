#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
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
    // cheking on mistake
    if ((!((string[1] == '+') || (string[1] == '-') || (string[1] == '/') || (string[1] == '*')) || (string[3] != '=') || !((string[0] == 'x') || (string[2] == 'x'))))
    {
        perror("Incorect expression");
    }

    if (string[0] == 'x')
    {
        // printf("re");
        switch (string[1])
        {
        case '+':
            return atoi(&string[4]) - atoi(&string[2]);

        case '-':
            return atoi(&string[4]) + atoi(&string[2]);
        case '*':
            return atoi(&string[4]) / atoi(&string[2]);

        case '/':
            return atoi(&string[4]) * atoi(&string[2]);
        }

        if (string[2] == 'x')
        {
            // printf("re");
            switch (string[1])
            {
            case '+':
                return atoi(&string[4]) - atoi(&string[2]);

            case '-':
                return atoi(&string[4]) + atoi(&string[2]);
            case '*':
                return atoi(&string[4]) / atoi(&string[2]);

            case '/':
                return atoi(&string[4]) * atoi(&string[2]);
            }
        }
    }
    int main(void)
    {
        int res = calc("x+1=6");
        printf("%d", res);

        // char *expression[] = {"2+x=5", "x+2=5", "2+x=5", "x-5=2", "5-x=2", "x=5*2", "x*5=10", "9*9=x", "x=10/3", "x/2=5", "10/x=5"};

        // int len = sizeof(expression) / sizeof(char *);

        // for (int i = 0; i < len; i++)
        //     printf("%s x=%d\n", expression[i], Calc(expression[i]));
    }