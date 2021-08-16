#include<stdio.h>
main()
{
    int ans;
    long long unsigned x,y;
    while(1)
    {
        scanf("%lld%lld",&x,&y);
        if(x==0&&y==0)
            return 0;
        ans=1;
        x%=10;
        while(y!=0)
        {
            if(y%2)
                ans=ans*x%10;
            y/=2;
            x=x*x%10;
        }
        printf("%d\n",ans);
    }
}
