#include<stdio.h>
#define N 100
#define Infinity 9999
main()
{
    int G[N][N],cost[N][N],dis[N],pre[N],ans[N],mark[N];
    int i,j,n,start,end,mindis,u,v,count,next;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==0)
                cost[i][j]=Infinity;
            else
                cost[j][j]=G[i][j];
        }
    scanf("%d%d",&start,&end);
    for(i=1; i<=n; i++)
    {
        dis[i]=cost[start][i];
        pre[i]=start;
        mark[i]=0;
    }
    mark[start]=count=1;
    dis[start]=0;
    while(count<n)
    {
        mindis=Infinity;
        for(i=1; i<=n; i++)
            if(dis[i]<mindis&&!mark[i])
            {
                mindis=dis[i];
                next=i;
            }
        mark[next]=1;
        for(i=1; i<=n; i++)
            if(mindis+cost[next][i]<dis[i]&&!mark[i])
            {
                dis[i]=mindis+cost[next][i];
                pre[i]=next;
            }
        count++;
    }
    j=end;
    for(i=0; j!=start; i++)
    {
        ans[i]=j;
        j=pre[j];
    }
    ans[j]=start;
    for(i=j; i>0; i--)
        printf("%d ",ans[i]);
    printf("%d\n",ans[0]);
    return 0;
}
