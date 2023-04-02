#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#define N 10
int n,i,j,comp,count=0;
int matrix[N][N],minmat[N][2],path[N];
void tsp(int p);
int mincost(int p,int q);
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int min=INT_MAX,min2=INT_MAX;
        for(j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j]!=0)
            {
                if(matrix[i][j]<min)
                {
                    min2=min;
                    min=matrix[i][j];
                    minmat[i][0]=min;
                    minmat[i][1]=min2;
                }
                else if(matrix[i][j]<min2)
                {
                    min2=matrix[i][j];
                    minmat[i][1]=min2;

                }
            }
        }

    }
    for(i=0;i<n;i++)
    {
        path[i]=-1;
    }
    path[0]=0;
    tsp(0);
    path[n]=0;
    comp=0;
    for(i=0;i<n;i++)
    {
        comp+=(matrix[path[i]][path[i+1]]);
    }
    printf("%d\n",comp);
    for(i=0;i<=n;i++)
        printf("%d ",path[i]+1);
}

void tsp(int p)

{
    int ind,min=INT_MAX;
    for(i=0;i<n;i++)
    {
        int flag=0;
        for(int a=0;a<n;a++)
        {
            if(path[a]==i)
            {
              flag=-1;
              break;
            }

        }
        if(flag<0)
            continue;
        comp=mincost(p,i);
        if(comp<=min)
        {
            min=comp;
            ind=i;
        }
    }
    count++;
    path[count]=ind;
    minmat[p][1]=matrix[p][ind];
    if(count==n)
        return;
    else
        tsp(ind);
}

int mincost(int p,int q)
{
    int sum=0;

    for(j=0;j<n;j++)
    {

        if(j==q)
        {
            if(matrix[p][j]!=0)
                sum+=(minmat[p][0]+matrix[p][j]);
        }
        else
            sum+=(minmat[j][0]+minmat[j][1]);
    }
    return sum/2;
}
