#include<stdio.h>
#include<math.h>
int max(int,int);
void warshal(int p[10][10],int n) {
	int i,j,k;
	for (k=1;k<=n;k++)
	  for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	    p[i][j]=max(p[i][j],p[i][k]&&p[k][j]);
}
int max(int a,int b)
{
	if(a>b)
	 return(a);
    else
	 return(b);
}
int main() {
	int p[10][10],i,j;
	for (i=1;i<=4;i++)
    {
		for (j=1;j<=4;j++)
		   scanf("%d",&p[i][j]);
	}
	warshal(p,4);
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		   printf("%d ",p[i][j]);
		printf("\n");
	}
}
