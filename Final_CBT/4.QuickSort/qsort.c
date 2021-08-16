#include<stdio.h>
#define N 100

int num[N];
int n;

void swap(int i,int j)
{
    int temp,k;
    temp=num[i];
    num[i]=num[j];
    num[j]=temp;
    for(k=0;k<n-1;k++)
        printf("%d ",num[k]);
    printf("%d\n",num[n-1]);
    return;
}

void q_sort(int left,int right)
{
    int pivot,i,j;
    if(left<right)
    {
        pivot=num[left];
        i=left+1;
        j=right;
        while(1)
        {
            while(num[i]<pivot&&i<=right)
                i++;
            while(num[j]>pivot&&j>=0)
                j--;
            if(i>=j)break;
            swap(i,j);
        }
        if(left!=j)
            swap(left,j);
        q_sort(left,j-1);
        q_sort(j+1,right);
    }
    return;
}

main()
{
    int i,j;
    freopen("in.txt","r",stdin);
    for(n=0;scanf("%d",num+n)!=EOF;n++);
    q_sort(0,n-1);
    return 0;
}
