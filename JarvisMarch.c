#include<stdio.h>
struct Point
{
    int x;
    int y;
};
typedef struct Point Point;

void jarvisMarch(Point *points, int n, int *convexHull, int *hullIdx);
int direction(Point p0, Point p1, Point p2);

int main()
{
    int n = 10;
    Point points[n];
    int convexHull[n];
    int hullIdx;
    for(int i = 0; i<n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    jarvisMarch(points, n, convexHull, &hullIdx);
    for(int i = 0; i<hullIdx; i++)
    {
        printf("%d %d\n", points[convexHull[i]].x, points[convexHull[i]].y);
    }
}


void jarvisMarch(Point *points, int n, int *convexHull, int *hullIdx)
{

    int pIdx = 0;
    for(int i = 1; i<n; i++)
    {
        if(points[i].x < points[pIdx].x)
        {
            pIdx = i;
        }
    }
    int p = pIdx;
    int q = (p + 1) % n;
    *hullIdx = 0;
    do{
        for(int j = 0; j<n; j++)
        {
            if(p != j && q != j && direction(points[p], points[q], points[j]) > 0)
            {
                q = j;
            }
        }
        p = q;
        convexHull[(*hullIdx)++] = p;
        q = (p + 1) % n;
    }while(p != pIdx);
}

int direction(Point p0, Point p1, Point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
