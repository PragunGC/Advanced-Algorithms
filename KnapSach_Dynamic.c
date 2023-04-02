#include <stdio.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int n,W,i,j,temp;
    scanf("%d",&n);
    scanf("%d",&W);

    int weight[n], profit[n], sortWID[n], result[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&weight[i]);
        sortWID[i]=i;
        result[i]=0;
    }
    for (i=0;i<n;i++)
    {
        scanf("%d",&profit[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(weight[sortWID[j]] > weight[sortWID[j+1]])
            {
                temp=sortWID[j];
                sortWID[j]=sortWID[j+1];
                sortWID[j+1]=temp;
            }
        }
    }
    int knapsack[n+1][W+1];
    for (i=0;i<=n;i++)
    {
        for (j=0;j<W+1;j++)
        {
            if (i==0 || j==0)
                knapsack[i][j]=0;
            else if (weight[sortWID[i-1]]<=j)
                knapsack[i][j]=max(profit[sortWID[i-1]]+knapsack[i-1][j-weight[sortWID[i-1]]],knapsack[i-1][j]);
            else
                knapsack[i][j] = knapsack[i-1][j];
        }
    }

    int allW=W;
    int profVal=knapsack[n][allW];
    for(i=n;i>=0;i--)
    {
        if(profVal!=knapsack[i][allW])
        {
            result[sortWID[i]]=1;
            allW=allW-weight[sortWID[i]];
            profVal = knapsack[i][allW];
            if(allW==0)
                break;
        }
        else
        {
            result[sortWID[i-1]]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }

    return 0;
}
