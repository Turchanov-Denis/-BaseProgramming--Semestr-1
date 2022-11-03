#include <stdio.h>
#define Size 6

int printArr(int arr[Size][Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    int arr[Size][Size] = {0};
    int counter = 1;
    // fill full matrix
    // change: the matrix is imaginary extended, filling occurs only if the condition is met
    for (int i = 1; i <= Size * 2; i++)
    {
        if (i % 2 == 0)
        {
            int m = i;
            int n = 1;
            while (m > 0)
            {
                if ((m <= Size) && (m > 0) && (n <= Size) && (n > 0))
                {
                    arr[m-1][n-1] = counter;
                    counter++;
                }

                m--;
                n++;
            }
        }
        else
        {
            int m = 1;
            int n = i;
            while (n > 0)
            {

                if ((m <= Size) && (m > 0) && (n <= Size) && (n > 0))
                {
                    arr[m-1][n-1] = counter;
                    counter++;
                }

                m++;
                n--;
            }
        }
    }
    // fill second part
    printArr(arr);
}