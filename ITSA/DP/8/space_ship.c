#include<stdio.h>
#include<stdlib.h>

int n,a[1010],b[1010];

int choose(int e1,int e2,int n)
{
    int ta,tb,tc,td;
    //printf("e1:%d e2:%d\n",e1,e2);
    if(n==0)
        return e1<e2?e1:e2;
    ta=abs(a[n-1]-a[n])+e1;
    tb=abs(a[n-1]-b[n])+e2;
    tc=abs(b[n-1]-a[n])+e1;
    td=abs(b[n-1]-b[n])+e2;
    e1=ta<tb?ta:tb;
    e2=tc<td?tc:td;
    n--;
    choose(e1,e2,n);
}

main()
{
    int i,t,energy;
    //freopen("in.txt","r",stdin);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1; i<=n; i++)
            scanf("%d%d",a+i,b+i);
        a[0]=b[0]=1000;
        energy=choose(0,0,n);
        printf("%d\n",energy);
    }
}
