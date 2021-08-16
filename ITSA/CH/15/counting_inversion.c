#include<stdio.h>

int main(void)
{
    int ncase,n,a[1000],count,i,j;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        count=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[j]<a[i])
                    count++;
        printf("%d\n",count);
    }
    return 0;
}
