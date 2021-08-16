#include<stdio.h>
main()
{
    int m,n,time=0,a[5],b[10],i;
    while(scanf("%d",&n)!=EOF)
    {
    time=0;
    scanf("%d",&m);
    a[0]=n%10;
    a[1]=n/10;
    for(i=0;i<7;i++)
    {
        b[i]=m%10;
        m=m/10;
    }
    for(i=0;i<6;i++)
        if(a[0]==b[i]&&a[1]==b[i+1])
            time++;
    printf("%d\n",time);
    }return 0;
}
