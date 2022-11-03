#include <stdio.h>
#define Size 5

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
    // int x = 0,
    //     y = 0,
    //     sCount = 0,
    //     arr[N][N] = {0};

    // for (int dyStep = 0; dyStep < N; dyStep++)
    // {
    //     y = 0;
    //     x = dyStep;
    //     for (int dxStep = 0; dxStep < dyStep + 1; dxStep++)
    //     {
    //         arr[y][x] = ++sCount;
    //         y++;
    //         x--;
    //     }
    // }
    int arr[Size][Size] = {0};
    int counter = 1;
    for (int i = 0; i < Size; i++)
    {
        if (i % 2 == 0)
        {
            int m = i;
            int n = 0;
            while (m >= 0)
            {
                arr[m][n] = counter;
                m--;
                n++;
                counter++;
            }
        }
        else
        {
            int m = 0;
            int n = i;
            while (n >=0)
            {
                arr[m][n] = counter;
                m++;
                n--;
                counter++;
            }
        }
    }
    printArr(arr);
}