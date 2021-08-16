
#include<stdio.h>
#define N 1005

main()
{
    int ncase,n,temp,i,j,total,sum[N],time[N];
    //freopen("in.txt","r",stdin);
    total=0;
    for(i=0; i<N; i++)
        sum[i]=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&time[i]);
    time[0]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=n-i; j++)
            if(time[j]>time[j+1])
            {
                temp=time[j];
                time[j]=time[j+1];
                time[j+1]=temp;
            }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<i; j++)
            sum[i]+=time[j]*2;
        sum[i]+=time[i];
    }
    for(i=1; i<=n; i++)
        total+=sum[i];
    printf("%d\n",total);
}
