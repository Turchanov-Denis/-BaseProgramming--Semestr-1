#include <stdio.h>
#include <math.h>
double polynom(char *expr, double x)
{
    double count = 0.0;
    printf("%s\n", expr);
    for (int i = 0; expr[i] != 0; i++){
        switch (expr[i])
        {
        case ' ': // check space
            break;
        default:
            int flag = (expr[i] == '-') ? 0 : 1;
            if ((expr[i] == '+') || (expr[i] == '-')) {
                i++;
            }
            // check coefficient
            if (expr[i] == 'x'){
                if (expr[i + 1] == '^'){
                    i+=2;
                    count = (flag) ? count+pow(x, expr[i] - '0') : count-pow(x, expr[i] - '0');
                } // alone x
                else {
                    count = (flag) ? count+x: count-x;
                }
            }
            else {
                int coefficient = expr[i] - '0'; // if coefficient two-digit number
                if (((expr[i + 1] - '0') >= 0) && ((expr[i + 1] - '0') <= 9)){
                    i++;
                    coefficient = coefficient * 10 + (expr[i] - '0');
                }
                if (expr[i + 1] == '*') { // check on just digital
                    i+=2;
                    if (expr[i] == 'x'){
                        if (expr[i + 1] == '^')
                        {
                            i+=2;
                            count = (flag) ? count+coefficient * pow(x, expr[i] - '0'):count-coefficient * pow(x, expr[i] - '0');
                        }
                    }
                }
                else { // it is just digital
                    count= (flag) ? count+coefficient:count-coefficient;
                }
            }
            break;
        }
    }
    return count;
}
int main(){
    char *expr = "x^4+15*x^3-3*x^2+x-2";
    double x = 3.0;
    printf(" y(% f) = % s returns % f ", x, expr, polynom(expr, x));
}