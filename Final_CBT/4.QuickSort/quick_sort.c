#include<stdio.h>

int num[100],n;

void swap(int i,int j)
{
    int temp,k;
    temp=num[i];
    num[i]=num[j];
    num[j]=temp;
    for(k=0; k<n-1; k++)
        printf("%d ",num[k]);
    printf("%d\n",num[n-1]);
    return;
}

void quick_sort(int left,int right)
{
    int i,j,k,pivot;
    if(left<right)
    {
        i=left+1;
        j=right;
        pivot=num[left];
        while(1)
        {
            while(i<=right&&num[i]<pivot)
                i++;
            while(j>=0&&num[j]>pivot)
                j--;
            if(i>=j)break;
            swap(i,j);
        }
        if(left!=j)
        swap(left,j);
        quick_sort(left,j-1);
        quick_sort(j+1,right);
    }
    return;
}

main()
{
    int i,j,k;
    freopen("in.txt","r",stdin);
    i=0;
    while(scanf("%d",&num[i++])!=EOF)
        n=i;
    quick_sort(0,n-1);
}
