#include <stdio.h>
#include <stdlib.h>

int calc(char string[])
{
    // check len
    int len = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
     len++;   
    }
    if (len!=5) {
        printf("Incorect expression down \n");
        return 0;
    }
    // check view x=...
    if ((string[0] == 'x') && (string[1] == '=') ) {
        int vars[] = {atoi(&string[2]),atoi(&string[4])};
        switch (string[3])
        {
        case '+':
            return vars[0] + vars[1];

        case '-':
           return vars[0] - vars[1];
        case '*':
            return vars[0] * vars[1];

        case '/':
           return vars[0] / vars[1];
        }
    }
    // cheking on mistake for simple extenssion x+... = ...
    if ((!((string[1] == '+') || (string[1] == '-') || (string[1] == '/') || (string[1] == '*')) || (string[3] != '=') || !((string[0] == 'x') || (string[2] == 'x'))))
    {
        printf("Incorect expression \n");
        return;}
    //calculate
    int vars[] = {atoi(&string[4]),atoi(&string[2])}; 
    if (string[2] == 'x') {vars[0] = atoi(&string[4]);vars[1] = atoi(&string[0]); }
    switch (string[1])
        {
        case '+':
            return vars[0] - vars[1];
        case '-':
            if (string[2] == 'x') {return vars[1] - vars[0];}
           return vars[0] + vars[1];
        case '*':
            return vars[0] / vars[1];
        case '/':
        if (!vars[1]) {printf("Incorect expression \n"); return;};
           return vars[0] * vars[1];
        }
}
    int main(void)
    {
        char *expression[] = {"x=10/3","2+x=5", "x+2=5", "2+x=5", "x-5=2", "5-x=2", "x=5*2", "x*5=10", "9*9=x", "x=10/3", "x/2=5", "10/x=5"};
        int len = sizeof(expression) / sizeof(char *);
        for (int i = 0; i < len; i++)
            printf("%s x=%d\n", expression[i], calc(expression[i]));
    }