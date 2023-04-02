#include <stdio.h>
#define n 6
int fulkersonKarp(int *resnet,int s,int t);
int findAugmentingPath(int *resnet,int *parent,int t);
int idx(int x,int y);


int main()
{

    int resnet[n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            scanf("%d",&resnet[i][j]);
        }
    }

    printf("Maximum flow is %d", fulkersonKarp((int *)resnet, 0,5));

}

int fulkersonKarp(int *resnet,int s,int t)
{
    int parent[n];
    int maxFlow=0;
    while (findAugmentingPath(resnet,parent,t))
    {

        int minResCapacity=resnet[idx(parent[t],t)];
        for (int i=parent[t];i!=s;i=parent[i])
        {
            if (minResCapacity>resnet[idx(parent[i],i)])
            {
                minResCapacity=resnet[idx(parent[i],i)];
            }
        }

        for (int i=t;i!=s;i=parent[i])
        {
            resnet[idx(i,parent[i])]+=minResCapacity;
            resnet[idx(parent[i],i)]-=minResCapacity;
        }
        maxFlow+=minResCapacity;
    }
    return maxFlow;
}

int findAugmentingPath(int *resnet, int *parent, int t)
{
    int iterQueue[n],visited[n],front=0,rear=1;
    parent[0]=-1;
    iterQueue[0]=0;
    for (int p=0;p<n;p++)
    {
        visited[p]=0;
    }
    visited[0]=1;
    while (front!=rear)
    {
        int i=iterQueue[front];
        front=(front+1)%n;

        for (int j=0;j<n;j++)
        {
            if (resnet[idx(i,j)]>0 && !visited[j])
            {
                parent[j]=i;
                if (j==t)
                    return 1;
                visited[j]=1;
                iterQueue[rear]=j;
                rear=(rear+1)%n;

            }
        }
    }
    return 0;
}

int idx(int x,int y)
{
    return (n*x+y);
}
