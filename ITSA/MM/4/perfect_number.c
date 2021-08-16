#include<stdio.h>
int main(void)
{
    int ncase,n,i,sum,flag=0;
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
        if(flag!=0)
            printf("\n");
        if(sum==n)
            printf("perfect");
        else
            printf("nonperfect");
        flag++;
    }
    return 0;
}
