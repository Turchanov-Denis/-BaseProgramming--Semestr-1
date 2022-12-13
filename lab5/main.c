#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct Vertex
{
    float x, y;
} Vertex; // define structure

static const Vertex *source_vertex;

int sort_by_angle(const Vertex *arg1, const Vertex *arg2)
{
    Vertex
        vector1 = {arg1->x - source_vertex->x, arg1->y - source_vertex->y},
        vector2 = {arg2->x - source_vertex->x, arg2->y - source_vertex->y},
        vector_OX = {0.0, 100.0};
    // find cos
    float cos1 = (vector1.x * vector_OX.x + vector1.y * vector_OX.y) / ((pow(vector1.x * vector1.x + vector1.y * vector1.y, 0.5)) * (pow(vector_OX.x * vector_OX.x + vector_OX.y * vector_OX.y, 0.5)));
    float cos2 = (vector_OX.x * vector2.x + vector_OX.y * vector2.y) / ((pow(vector_OX.x * vector_OX.x + vector_OX.y * vector_OX.y, 0.5)) * (pow(vector2.x * vector2.x + vector2.y * vector2.y, 0.5)));

    if (acos(cos1)>acos(cos2)) 
    {
        return 1;
    }
    if (cos1==cos2) {
        return 0;
    }
    return -1;
}

float traverse_clockwise(float coord[], int n)
{
    Vertex *array;
    array = (Vertex *)malloc(sizeof(Vertex) * n);
    float perimeter = 0.0;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        array[i].x = coord[counter];
        array[i].y = coord[counter + 1];
        counter += 2;
    }
    // search left bottom vertex
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((array[j].y < array[j + 1].y) && (array[j].x < array[j + 1].x))
            {
                Vertex tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    source_vertex = &array[0];
    // sort
    qsort(array + 1, n - 1, sizeof *array, sort_by_angle);
    for (int i = 0; i < n; ++i)
    {
        if (i == (n - 1))
        {
            perimeter += pow(pow(array[i].x - array[0].x, 2) + pow(array[i].y - array[0].y, 2), 0.5);
            printf("{ %f, %f } \n", array[i].x, array[i].y);
            break;
        }
        perimeter += pow(pow(array[i].x - array[i + 1].x, 2) + pow(array[i].y - array[i + 1].y, 2), 0.5);
        printf("{ %f, %f } \n", array[i].x, array[i].y);
    }
    return perimeter;
}

int main()
{
    float rect[] = {1, 5, 7, 1, 7, 5, 1, 1};
    int n = (sizeof(rect) / sizeof(float)) / 2.0;
    printf("rect return %f\n", traverse_clockwise(rect, n));

    float star[] = {3.97, 0.82, 2.26, 3.69, 5.39, 2.16, 2.03, 2.11, 5.36, 4.06};
    int n1 = (sizeof(star) / sizeof(float)) / 2.0;
    printf("star return %f\n", traverse_clockwise(star, n1));

    float enneagon[] = {76, 67.1, -8.3, 18, 55, 93.3, 77, 33, 21.3, 99, -20, 50, -8.3, 82, 55, 6.7, 21.3, 0.76};
    int n2 = (sizeof(enneagon) / sizeof(float)) / 2.0;
    printf("enneagon return %f", traverse_clockwise(enneagon, n2));
}