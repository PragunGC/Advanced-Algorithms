#include <stdio.h>

int main()
{
    int n,i,j,temp;
    float s;
    scanf("%f",&s);
    scanf("%d",&n);
    float w[n],v[n],rt[n],r[n],sum=0;
    int ind[n];
    for(i=0;i<n;i++)
    {
        scanf("%f",&w[i]);
        ind[i]=i;
        r[i]=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%f",&v[i]);
        rt[i]=v[i]/w[i];
    }
    for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(rt[ind[j]]<rt[ind[j+1]])
                {
                    temp=ind[j];
                    ind[j]=ind[j+1];
                    ind[j+1]=temp;
                }
            }
        }

    for(i=0;i<n;i++)
    {
        sum+=w[ind[i]];
        r[ind[i]]=1;
        if(sum>s)
        {
            sum-=w[ind[i]];
            r[ind[i]]=(s-sum)/w[ind[i]];
            break;
        }
    }
    for(i=0;i<n;i++)
        printf("%.1f ",r[i]);
}
