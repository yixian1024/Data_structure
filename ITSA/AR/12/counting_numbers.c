#include<stdio.h>
int main(void)
{
    int ncase,num[110],i,j,n=0,temp,count;
    n=0;
    while(1)
    {
        scanf("%d",&num[n]);
        if(num[n]==-999)break;
        n++;
    }
    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
        {
            if(num[j]<num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    j=0;
    while(i<n)
    {
        i=j;
        count=1;
        for(j=i+1; j<n; j++)
        {
            if(num[i]==num[j])
                count++;
            else break;
        }
        if(i!=n)
            printf("%d %d\n",num[i],count);
    }
    return 0;
}
