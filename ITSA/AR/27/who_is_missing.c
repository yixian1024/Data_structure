#include<stdio.h>

int main(void)
{
    int n,i,num[70000];
    scanf("%d",&n);
    for(i=1; i<n; i++)
        scanf("%d",num+i);
    for(i=1; i<=n; i++)
    {
        if(num[i]!=i)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
