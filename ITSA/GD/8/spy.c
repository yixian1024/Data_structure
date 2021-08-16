
#include<stdio.h>

main()
{
    int ncase,n,i,monitor[10000],boss[10000],total;
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=1; i<n; i++)
        scanf("%d",boss+i);
    total=0;
    for(i=0; i<n; i++)
        monitor[i]=0;
    for(i=n-1; i>0; i--)
        if(monitor[i]==0)
            monitor[boss[i]]=1;
    for(i=0; i<n; i++)
        if(monitor[i]==1)
            total++;
    printf("%d\n",total);
}
