#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int vertices[n];
    int adjmat[n][n];
    for(int i=0;i<n;i++)
    {
        vertices[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adjmat[i][j]);
        }
    }
    int c[n];
    int count=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(adjmat[i][j]==1)
            {
                c[count]=j;
                c[count+1]=i;
                for(int k=0;k<n;k++)
                {
                    adjmat[i][k]=0;
                    adjmat[j][k]=0;
                    adjmat[k][i]=0;
                    adjmat[k][j]=0;
                }
                count+=2;
                if(count>=n)
                    count-=2;
            }
        }
    }
    for(int i=0;i<count;i++)
    {
        vertices[c[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",vertices[i]);
    }
}

        for(int j=n-1;j>=0;j--)
        {
            if(adjmat[i][j]==1)
            {
                c[count]=j
                c[count+1]=i;
                for(int k=0;k<n;k++)
                {
                    adj[i][k]=0;
                    adj[j][k]=0;
                    adj[k][i]=0;
                    adj[k][j]=0;
                }
                count+=2;
                if(count>=n)
                    count-=2;
            }
        }
    }
    for(int i=0;i<count;i++)
    {
        vertices[c[i]]=1;
    }
    for(int i=0;i<count;i++)
    {
        printf("%d",vertices[i]);
    }
}
