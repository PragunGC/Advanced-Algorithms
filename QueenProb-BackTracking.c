#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int board[20],count;

int main()
{
void queen(int row,int n);
int n,i,j;
scanf("%d",&n);
queen(1,n);
return 0;
}

void queen(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
   board[row]=column;
   if(row==n)
   {
    print(n);
   }
   else
    queen(row+1,n);
  }
}
}

int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
return 1;
}

void print(int n)
{
int i,j;
if(count!=0)
{
    for(i=1;i<=n;++i)
    {
    printf("\n");
    for(j=1;j<=n;++j)
    {
        if(board[i]==j)
            printf("1 ");
        else
            printf("0 ");
    }
    }
}
++count;

}



