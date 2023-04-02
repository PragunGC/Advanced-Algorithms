#include<stdio.h>
int main()
{
    int n,c[10],a[10],i,j,amt,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        a[i]=0;
    }
    scanf("%d",&amt);
    for(i=0;i<n;i++)
    {
        if(amt/c[i]!=0)
        {
            a[i]=(amt/c[i]);
            sum+=a[i];
            amt=amt%c[i];
        }
        if(amt==0)
            break;
    }
    printf("%d",sum);
    for(i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            for(j=0;j<a[i];j++)
            {
                if(j==0 && i==0)
                    printf("%d",c[i]);
                else
                    printf("+%d",c[i]);
            }
        }
    }
}


