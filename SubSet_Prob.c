#include <stdio.h>

int subsetSum(int *set,int *index,int n,int acc,int target,int *result,int i,int *found);
int main()
{
    int n, target;
    scanf("%d",&n);
    int set[n];
    int result[n];
    int index[n];
    int found=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&set[i]);
        result[i]=0;
        index[i]=i;
    }
    scanf("%d",&target);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(set[index[j]]>set[index[j+1]])
            {
                int temp=index[j];
                index[j]=index[j+1];
                index[j+1]=temp;
            }
        }
    }

    subsetSum(set,index,n,0,target,result,0,&found);
    if(found==0)
    {
        printf("Solution cannot be found");
    }
    return 0;
}

int subsetSum(int *set,int *index,int n,int acc,int target,int *result,int i,int *found)
{
    if(acc<target && i<n)
    {
        result[index[i]]=1;
        acc+=set[index[i]];
        if(subsetSum(set,index,n,acc,target,result,i+1,found)!=1)
        {
            result[index[i]]=0;
            acc-=set[index[i]];
            subsetSum(set,index,n,acc,target,result,i+1,found);
        }
        return 0;
    }
    else if(acc==target)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",result[j]);
        }
        printf("\n");
        *found = 1;
        return 1;
    }
    return 0;
}
