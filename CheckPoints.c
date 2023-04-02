#include<stdio.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point Point;

int intersection(Point p1, Point p2, Point p3, Point p4);
int direction(Point p0,Point p1,Point p2);
int pointscolliner(Point p0,Point p1,Point p2);
int min(int a, int b);
int max(int a, int b);

int main()
{
    Point points[4];
    for(int i = 0; i<4; i++)
    {
        scanf("%d", &points[i].x);
        scanf("%d", &points[i].y);
    }
    int res=intersection(points[0], points[1], points[2], points[3]);
    if(res)
    {
        printf("Line segments intersect");
    }
    else
    {
        printf("Line segments do not intersect");
    }
    return 0;
}
int intersection(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    if(d1 != d2 && d3 != d4)
    {
        return 1;
    }
    else if(d1 == 0 && pointscolliner(p3, p4, p1))
    {
        return 1;
    }
    else if(d2 == 0 && pointscolliner(p3, p4, p2))
    {
        return 1;
    }
    else if(d3 == 0 && pointscolliner(p1, p2, p3))
    {
        return 1;
    }
    else if(d4 == 0 && pointscolliner(p1, p2, p4))
    {
        return 1;
    }
    return 0;
}

int direction(Point p0,Point p1,Point p2)
{
    int p1xp2 = (p1.x - p0.x)(p2.y - p0.y) - (p2.x - p0.x)(p1.y - p0.y);
    if(p1xp2 > 0) //p1 is clockwise from p2
    {
        return 1;
    }
    else if(p1xp2 < 0) // p1 is anticlockwise from p2
    {
        return -1;
    }
    else    //Collinear
    {
        return 0;
    }
}

int pointscolliner(Point p0,Point p1,Point p2)
{
    if(p2.x <= max(p0.x,p1.x) && p2.x >= min(p0.x,p1.x) && p2.y <= max(p0.y,p1.y) && p2.y >= min(p0.y,p1.y))
        return 1;
    return 0;
}

int min(int a, int b)
{
    return (a < b)? a : b;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
