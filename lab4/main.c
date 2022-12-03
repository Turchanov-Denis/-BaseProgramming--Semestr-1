#include <stdio.h>
#include <math.h>
double polynom(char *expr, double x)
{
    double count = 0.0;
    for (int i = 0; expr[i] != 0; i++)
    {
        switch (expr[i])
        {
        case '+':
            i++;
            if (expr[i] == 'x')
            {
                i++;
                if (expr[i] == '^')
                {
                    i++;
                    count += pow(x, expr[i] - '0');
                }
            }
            else
            {
                count += expr[i] - '0';
            }
            break;

        case '-':
            i++;
            if (expr[i] == 'x')
            {
                i++;
                if (expr[i] == '^')
                {
                    i++;
                    count -= pow(x, expr[i] - '0');
                }
            }
            else
            {
                count -= expr[i] - '0';
            }
            break;

        default:
            if (expr[i] == 'x')
            {
                i++;
                if (expr[i] == '^')
                {
                    i++;
                    count += pow(x, expr[i] - '0');
                }
            }
            else
            {
                count += expr[i] - '0';
            }
            break;
        }
    }

    printf("%f",count);
}

int main()
{
    char *expr = "-22+5*x 3 +x";
    double x = 3.0;
    polynom(expr, x);
    // printf(" y(% f) = % s returns % f ", x, expr, polynom(expr, x));
}