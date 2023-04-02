#include <stdio.h>

int min(int a,int b);
int carAssem(int *a,int *t,int *e,int *x,int s);
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n*2],t[(n-1)*2],e[2],x[2];
    for(i=0;i<(n*2);i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<((n-1)*2);i++)
    {
        scanf("%d",&t[i]);
    }
    for(i=0;i<2;i++)
        scanf("%d",&e[i]);
    for(i=0;i<2;i++)
        scanf("%d",&x[i]);
    printf("%d",carAssem(a,t,e,x,n));

    return 0;
}

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int carAssem(int *a,int *t,int *e,int *x,int s)
{
    int T1[s],T2[s],k;

    T1[0]=e[0]+a[0];
    T2[0]=e[1]+a[0+s];

    for (k=1;k<s;k++)
    {
        T1[k] = min(T1[k-1]+a[k],T2[k-1]+t[k+s-1]+a[k]);
        T2[k] = min(T2[k-1]+a[k+s],T1[k-1]+t[k-1]+a[k+s]);
    }

    return min(T1[s-1]+x[0],T2[s-1]+x[1]);
}
