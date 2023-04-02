#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#define N 10
int n,i,j,k,comp;
int matrix[N][N],avail[N],job[N];
void node(int p);
int lb(int p,int q);
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&matrix[i][j]);
    }
    for(i=0;i<n;i++)
    {
        job[i]=-1;
    }
    node(0);
    printf("%d\n",comp);
    for(i=0;i<n;i++)
        printf("%c:%d ",97+i,job[i]+1);
}
void node(int p)
{
    int min=INT_MAX;
    int ind;
    for(i=0;i<n;i++)
    {
        int flag=0;
        for(int a=0;a<n;a++)
        {
            if(job[a]==i)
            {
              flag=-1;
              break;
            }

        }
        if(flag<0)
            continue;
        comp=lb(p,i);
        if(comp<=min)
        {
            ind=i;
            min=comp;
        }

    }
    job[p]=ind;
    if(p==n-1)
        return;
    else
        node(p+1);
}

int lb(int p,int q)
{
    int sum=0;
    for(j=0;j<n;j++)
    {
        avail[j]=-1;
        if(job[j]>=0)
            {
                avail[job[j]]=0;
                sum+=matrix[j][job[j]];
            }

    }

    sum+=matrix[p][q];
    avail[q]=0;

    for(j=p+1;j<n;j++)
    {
        int min_temp=INT_MAX;
        for(k=0;k<n;k++)
        {
            if(avail[k]==0)
                continue;
            else
            {
                if(min_temp>=matrix[j][k])
                    {
                        min_temp=matrix[j][k];
                    }

            }
        }
        sum+=min_temp;
    }
    return sum;
}
