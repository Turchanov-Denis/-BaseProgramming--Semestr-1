#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file_ptr;
    file_ptr = fopen("text.txt", "r+a");
    // store for mark visitor in definitely hour
    int counter[24] = {0};
    char text[50];
    if (file_ptr != NULL)
    {
        printf("File text.txt opened\n\n");
    }
    while (fgets(text, 50, file_ptr))
    {
        // printf("%s\n", text);
        int current = (text[0] == '0') ? (text[1] - '0') : (text[0] - '0') * 10 + (text[1] - '0');
        int end = (text[6] == '0') ? (text[7] - '0') : (text[6] - '0') * 10 + (text[7] - '0');
        // check hour
        while (current <= end)
        {
            counter[current]++;
            // printf("%d\n", current);
            current++;
        }
    }
    // check max
    int maxCount = 0;
    for (int i = 0; i < 24; i++)
    {

        if (counter[i] > maxCount)
        {
            maxCount = counter[i];
        }
    }
    printf("Max visitor is %d\n", maxCount);
}