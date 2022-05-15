#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct point
{
    int x;
    int y;
};

struct point *predef_points(struct point *points)
{
    struct point pre_points[] = {
        {6, 17}, {7, 6}, {18, 4}, {1, 18}, {10, 6}, {4, 14}, {6, 6}, {7, 17}, {10, 19}, {7, 7}};
    int i;
    points = calloc(10, sizeof(struct point));
    for (i = 0; i < 10; i++)
    {
        points[i] = pre_points[i];
    }
    return points;
}

int orientation(struct point i, struct point j, struct point k)
{
    int direction;
    direction = (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y);
    if (direction == 0)
    {
        return 0;
    }
    else if (direction > 0)
    {
        return 1;
    }
    else if (direction < 0)
    {
        return -1;
    }
}
void convex_hull(struct point points[], int count)
{
    struct point hull;
    int i, j, k, left;
    if (count < 3)
    {
        printf("For less than 3 given set of points is already convex\n");
        return;
    }
    left = 0;
    for (i = 0; i < count; i++)
    {
        if (points[i].x < points[left].x)
        {
            left = i;
        }
    }
    i = left;
    do
    {
        printf("%d, %d\n", points[i].x, points[i].y);
        j = (i + 1) % count;
        for (k = 0; k < count; k++)
        {
            if (orientation(points[i], points[k], points[j]) == -1)
            {
                j = k;
            }
        }
        i = j;
    } while (i != left);
}
void main(int argc, char *argv[])
{
    struct point *points;
    int count = 10;
    char choice;
    int i;
    printf("Use pre-defined set of points? [Y/y]> ");
    scanf("%c", &choice);
    if (choice != 'y' && choice != 'Y' && choice != '\n')
    {
        printf("Enter number of points> ");
        scanf("%d", &count);
        points = calloc(count, sizeof(struct point));
        printf("Enter all points in format x y per line\n");
        for (i = 0; i < count; i++)
        {
            scanf("%d %d", &points[i].x, &points[i].y);
        }
    }
    printf("Convex Hull of the given set of points is created by points: \n");
    convex_hull(points, count);
}
