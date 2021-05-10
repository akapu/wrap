#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

typedef struct point {
    int num;
    float x;
    float y;
} POINT;

int pntcmp(POINT*, POINT*);
int check(POINT*, int);
void fix(POINT*, int*);

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

    qsort(points, len_points, sizeof(POINT),
            (int (*)(const void *, const void *)) pntcmp);    

    POINT leftest = points[0];
    POINT rightest = points[len_points - 1];

    float slope = (leftest.y - rightest.y) / (leftest.x - rightest.x);
    float y_inter = leftest.y - (slope * leftest.x);

    POINT *hull = malloc(sizeof(POINT) * len_points);

    int i = 0;
    int len_hull = 0;

    for (i = 0; i < len_points; i++)
    {
        if (points[i].y < points[i].x * slope + y_inter)
            continue;

        hull[len_hull] = points[i];
        len_hull++;

        while (check(hull, len_hull))
            fix(hull, &len_hull);
    }

    for (i = len_points - 1; i > 0; i--)
    {
        if (points[i].y >=  points[i].x * slope + y_inter)
            continue;

        hull[len_hull] = points[i];
        len_hull++;

        while (check(hull, len_hull))
            fix(hull, &len_hull);
    }

    for (i = 0; i < len_hull; i++)
        printf("%d\n", hull[i].num);


    free(points);
    free(hull);
}

int pntcmp(POINT *first, POINT *second)
{
    return first->x - second->x;
}

int check(POINT *hull, int len_hull)
{
    if (len_hull < 3)
        return 0; 

    int x1, y1, x2, y2, x3, y3;

    x1 = hull[len_hull - 3].x;
    y1 = hull[len_hull - 3].y;

    x2 = hull[len_hull - 2].x;
    y2 = hull[len_hull - 2].y;

    x3 = hull[len_hull - 1].x;
    y3 = hull[len_hull - 1].y;

    float signed_area;

    signed_area = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (!(signed_area))
        if (((y1 > y2) && (y2 > y3)) || ((y3 > y2) && (y2 > y3)))
            return 1;

    if (signed_area < 0)
        return 0;
    else
        return 1;
}

void fix(POINT *hull, int *len_hull)
{
    hull[*len_hull - 2] = hull[*len_hull - 1];
    (*len_hull)--;
}
        
