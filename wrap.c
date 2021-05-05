#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

typedef struct point {
    int num;
    float x;
    float y;
} POINT;

int pntcmp(POINT*, POINT*);

int main()
{
    int len_points = 0;
    int num;
    float x, y;
    POINT *points = malloc(sizeof(POINT) * MAX_LEN);


    while (scanf("%d %f %f", &num, &x, &y) == 3)
    {
        points[len_points].num = num;
        points[len_points].x = x;
        points[len_points].y = y;
        len_points++;
    }
    
    qsort(points, len_points, sizeof(POINT*), pntcmp);    

    
    free(points);
}

int pntcmp(POINT *first, POINT *second)
{
    return first->x - second->x;
}
        
