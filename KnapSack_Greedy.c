#include<stdio.h>
int main()
{
    int n,lug[20],res[20],lim,sum=0,count;
    scanf("%d",&n);
    scanf("%d",&lim);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&lug[i]);
        res[i]=0;
    }
    count=n-1;
    for(int i=n-1;i>0;--i)
    {

        sum=sum+lug[i];
        res[i]=1;
        count--;
        if(sum>lim)
        {
            sum=sum-lug[count+1];
            res[count+1]=0;
            break;
        }

    }
    for(int i=0;i<n;i++)
        printf("%d ",res[i]);

}

