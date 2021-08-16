#include<stdio.h>
int main(void)
{
    int ncase,n,i,sum;
    //freopen("in.txt","r",stdin);
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        i=1;
        sum=0;
        while(i<n)
        {
            if(n%i==0)
                sum=sum+i;
            i++;
        }
        if(sum==n)
            printf("perfect\n");
        else
            printf("nonperfect\n");
    }
    return 0;
}
