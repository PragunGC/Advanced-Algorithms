#include <stdio.h>

int main()
{
    int n,tw,i,j,flag=1,sum=0;
    scanf("%d",&n);
    int w[n],p[n],r[n];
    for(i=0;i<n;i++)
    {
       scanf("%d",&w[i]);
       r[i]=0;
    }

    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    scanf("%d",&tw);
    for(i=1;i<=n;i++)
    {
        if(flag==0)
            break;
        for(j=0;j<n;j++)
        {
            if(p[j]==i)
            {
                sum+=w[j];
                r[j]=1;
                if(sum>tw)
                {
                    sum-=w[j];
                    r[j]=0;
                    flag=0;
                }
                break;
            }

        }

    }
    for(i=0;i<n;i++)
        printf("%d ",r[i]);
}
