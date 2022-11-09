#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int calc(char string[])
{
    // cheking on mistake
    if ((!((string[1] == '+') || (string[1] == '-') || (string[1] == '/') || (string[1] == '*')) || (string[3] != '=') || !((string[0] == 'x') || (string[2] == 'x'))))
    {
        printf("Incorect expression \n");
        return;
    }

    if (string[0] == 'x')
    {
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
     if (string[2] == 'x') {
            switch (string[1])
            {
            case '+':
                return atoi(&string[4]) - atoi(&string[0]);

            case '-':
                return atoi(&string[0]) - atoi(&string[4]);
            case '*':
                return atoi(&string[4]) / atoi(&string[0]);

            case '/':
                return atoi(&string[4]) * atoi(&string[0]);
            }
        }
    
}
    int main(void)
    {
        char *expression[] = {"2+x=5", "x+2=5", "2+x=5", "x-5=2", "5-x=2", "x=5*2", "x*5=10", "9*9=x", "x=10/3", "x/2=5", "10/x=5"};
        int len = sizeof(expression) / sizeof(char *);
        for (int i = 0; i < len; i++)
            printf("%s x=%d\n", expression[i], calc(expression[i]));
    }