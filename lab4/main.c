#include <stdio.h>
#include <math.h>
double polynom(char *expr, double x)
{
    double count = 0.0;

    printf("%s\n", expr);
    for (int i = 0; expr[i] != 0; i++)
    {
        switch (expr[i])
        {
            // check space
        case ' ':
            break;
        case '+':
            i++;
            // check coefficient
            if (expr[i] == 'x')
            {
                // dont have

                if (expr[i + 1] == '^')
                {
                    i++;
                    count += pow(x, expr[i] - '0');
                }
                // alone x
                else
                {
                    count += x;
                }
            }
            else
            {
                // have
                int coefficient = expr[i] - '0';
                // if coefficient two-digit number
                if (((expr[i + 1] - '0') >= 0) && ((expr[i + 1] - '0') <= 9))
                {
                    i++;
                    coefficient = coefficient * 10 + (expr[i] - '0');
                }

                if (expr[i + 1] == '*') // check on just digital
                {
                    i++;
                    i++;
                    if (expr[i] == 'x')
                    {

                        if (expr[i + 1] == '^')
                        {
                            i++;
                            i++;
                            count += coefficient * pow(x, expr[i] - '0');
                        }
                    }
                }
                else
                {
                    // it is just digital
                    count += coefficient;
                    break;
                }
            }
            break;
        case '-':
            i++;
            // check coefficient
            if (expr[i] == 'x')
            {
                // dont have

                if (expr[i + 1] == '^')
                {
                    i++;
                    count -= pow(x, expr[i] - '0');
                }
                // alone x
                else
                {
                    count -= x;
                }
            }
            else
            {
                // have
                int coefficient = expr[i] - '0';
                // if coefficient two-digit number
                if (((expr[i + 1] - '0') >= 0) && ((expr[i + 1] - '0') <= 9))
                {
                    i++;
                    coefficient = coefficient * 10 + (expr[i] - '0');
                }

                if (expr[i + 1] == '*') // check on just digital
                {
                    i++;
                    i++;
                    if (expr[i] == 'x')
                    {

                        if (expr[i + 1] == '^')
                        {
                            i++;
                            i++;
                            count -= coefficient * pow(x, expr[i] - '0');
                        }
                    }
                }
                else
                {
                    // it is just digital
                    count -= coefficient;
                    break;
                }
            }
            break;
        default:
            i++;
            // check coefficient
            if (expr[i] == 'x')
            {
                // dont have

                if (expr[i + 1] == '^')
                {
                    i++;
                    count += pow(x, expr[i] - '0');
                }
                // alone x
                else
                {
                    count += x;
                }
            }
            else
            {
                // have
                int coefficient = expr[i] - '0';
                // if coefficient two-digit number
                if (((expr[i + 1] - '0') >= 0) && ((expr[i + 1] - '0') <= 9))
                {
                    i++;
                    coefficient = coefficient * 10 + (expr[i] - '0');
                }

                if (expr[i + 1] == '*') // check on just digital
                {
                    i++;
                    i++;
                    if (expr[i] == 'x')
                    {

                        if (expr[i + 1] == '^')
                        {
                            i++;
                            i++;
                            count += coefficient * pow(x, expr[i] - '0');
                        }
                    }
                }
                else
                {
                    // it is just digital
                    count += coefficient;
                    break;
                }
            }
            break;
        }
    }

    // printf("%f", count);
    return count;
}

int main()
{
    char *expr = "-14+10*x^3+x";
    double x = 3.0;
    printf(" y(% f) = % s returns % f ", x, expr, polynom(expr, x));
}