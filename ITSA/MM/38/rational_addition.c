#include<stdio.h>
main()
{
    int p,q,m,n,temp,a,b;
    while(1)
    {
        scanf("%d/%d %d/%d",&p,&q,&m,&n);
        if(p==0&&q==0&&m==0&&n==0)
            return 0;
        a=m=n*p+m*q;
        b=n=q*n;
        while(1)
        {
            if(n==0)break;
            m=m%n;
            temp=m;
            m=n;
            n=temp;
        }
        a/=m;
        b/=m;
        printf("%d/%d\n",a,b);
    }
}
