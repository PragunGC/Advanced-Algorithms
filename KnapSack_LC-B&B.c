#include<stdio.h>
#include <stdlib.h>
#define N 10
int n,W,w=0,v=0,ub,i,j,k;
int index[N],weight[N],value[N],ratio[N],inclusion[N];
void knapsack(int p);
int main()
{
    int temp;
    scanf("%d",&n);
    scanf("%d",&W);
    for(i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
        index[i]=i;
        inclusion[i]=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&value[i]);
        ratio[i]=value[i]/weight[i];
    }
    for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(ratio[index[j]]<ratio[index[j+1]])
                {
                    temp=index[j];
                    index[j]=index[j+1];
                    index[j+1]=temp;
                }
            }
        }
    ub=v+((W-w)*ratio[index[0]]);
    knapsack(index[0]);
    printf("%d\n",ub);
    for(i=0;i<n;i++)
    {
        printf("%d ",inclusion[i]);
    }
}

 void knapsack(int p)
 {
    if(W>=(w+weight[p]))
    {
        w+=weight[p];
        v+=value[p];
        ub=v+((W-w)*ratio[index[p+1]]);
        inclusion[index[p]]=1;
    }
    else
        ub=v+((W-w)*ratio[p+1]);
    if(p==n-1)
        return;
    else
        knapsack(index[p+1]);

 }
