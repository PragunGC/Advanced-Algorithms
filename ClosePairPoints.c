#include <stdio.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};
typedef struct Point Point;

int main()
{
    int n = 6;
    Point points[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    float minVal = 99999;
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            float dist = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            if(dist< minVal)
            {
                minVal = dist;
            }
        }
    }

    printf("%.1f", minVal);
    return 0;
}
