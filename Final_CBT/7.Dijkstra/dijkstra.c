#include<stdio.h>
#define INFINITY 9999
#define MAX 100

int main()
{
    int G[MAX][MAX],i,j,k,n,start,end;
    int visited[MAX],cost[MAX][MAX],distance[MAX],pred[MAX],ans[MAX];
    int count,mindistance,nextnode;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
        }
    scanf("%d%d",&start,&end);
    for(i=1; i<=n; i++)
    {
        distance[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }
    distance[start]=0;
    count=visited[start]=1;
    while(count<n)
    {
        mindistance=INFINITY;
        for(i=1; i<=n; i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=1; i<=n; i++)
            if(mindistance+cost[nextnode][i]<distance[i]&&!visited[i])
            {
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
        count++;
    }
    j=end;
    for(i=0; j!=start; i++)
    {
        ans[i]=j;
        j=pred[j];
    }
    ans[i]=start;
    for(j=i; j>0; j--)
        printf("%d ",ans[j]);
    printf("%d\n",ans[0]);
    return 0;
}
