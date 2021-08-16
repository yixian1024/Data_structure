#include<stdio.h>

int main()
{
    int ncase,n,ans,i;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        ans=1;
        for(i=1;i<=n;i++)
            ans*=i;
        printf("%d\n",ans);
    }
    return 0;
}

