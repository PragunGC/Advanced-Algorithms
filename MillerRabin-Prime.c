#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int res[25];
int modexpo(int a,int u, int n);
int divtwo(int num)
{
    int flag=0;
    int count=0;
    while(flag!=1)
    {
        if(num%2==0)
        {
            count++;
            num=num/2;
        }
        else
            flag=1;

    }
    return count;
}
int boln(int b)
{
    int count=0;
    while(b!=0)
    {
        res[count]=b%2;
        b=b/2;
        count++;
    }
    return count;
}
int main()
{
    int prime;
    scanf("%d",&prime);
    int temp=prime-1;
    int s = divtwo(temp);
    temp=prime-1;
    int u = temp/pow(2,s);
    int a = 6;
    int seq[s+1];
    seq[0]=modexpo(a,u,prime);
    int flag=0;
    for(int i=1;i<=s;i++)
    {
        seq[i]=(seq[i-1]*seq[i-1])%prime;
        if(seq[i]==1 && seq[i-1]!=1 && seq[i-1]!=(prime-1))
            flag=1;
    }
    if(seq[s]!=1)
        flag=1;
    if(flag==1)
        printf("The number is not prime");
    else
        printf("The number is prime");
}
int modexpo(int a,int u, int n)
{
    int cnt=boln(u);
    int c=0,d=1;
    for(int i=cnt;i>=0;i--)
    {
       c=2*c;
       d=(d*d)%n;
       if(res[i]==1)
       {
          c=c+1;
          d=(d*a)%n;
       }
    }
    return d;
}
