#include<stdio.h>
#include<conio.h>
int main()
{
    int n,e,i,start[10],finish[10],a[10],end,count=0;
    scanf("%d",&n);
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
        scanf("%d",&start[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&finish[i]);
    }
    a[count]=0;
    count++;
    end=finish[0];
    for(i=1;i<n;i++)
    {
        if(start[i]>=end)
        {
            a[count]=i;
            end=finish[i];
            count++;
        }
    }
    printf("\n");
    for(i=0;i<e;i++)
    {
        printf("%d  ",a[i]);
    }
}
