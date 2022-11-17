#include <stdio.h>

int abba(int arr[8])
{
    char arrHex[8][8];
    int arrHexHelper[8][8];
    for (int i = 0; i < 8; i++)
    {
        int current = arr[i];
        if (current > 0)
        {
            for (int j = 7; j >= 0; j--)
            {
                // int rest = arr[i]%16;
                printf("%d - - %d \n", current, current % 16);
                arrHex[i][j] = ((current % 16) == 10) ? 'A' : (current % 16 == 11) ? 'B'
                                                                                   : '0';
                current = current / 16;
            }
        }
        else
        {
            current = abs(current);
            for (int j = 7; j >= 0; j--)
            {
                printf("%d - - %d \n", current, (15 - current % 16));
                int rest = (j != 7) ? (15 - current % 16) : (15 - current % 16) + 1;
                arrHex[i][j] = (rest == 10) ? 'A' : (rest == 11) ? 'B'
                                                                 : '0';
                current = current / 16;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c", arrHex[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int sample1[8] = {-1413863686, -1146374827, -1162027246, -1442185216,
                      184549376, 11534336, 655360, 179026592};
    abba(sample1);
}