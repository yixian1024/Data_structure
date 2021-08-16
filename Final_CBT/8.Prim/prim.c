#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
#define MAX 200

int G[MAX][MAX],spanning[MAX][MAX],n;
int main()
{
    int cost[MAX][MAX],count;
    int u,v,min_distance,distance[MAX],pre[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
            spanning[i][j]=0;
        }
    distance[0]=0;
    visited[0]=1;
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        pre[i]=0;
        visited[i]=0;
    }

    min_cost=0;        //cost of spanning tree
    no_of_edges=n-1;        //no. of edges to be added
    count=0;
    while(no_of_edges>0)
    {
        count++;
        //find the vertex at minimum distance from the tree
        min_distance=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }

        u=pre[v];

        //insert the edge in spanning tree
        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        printf("%d %d %d %d\n",count,u+1,v+1,distance[v]);
        no_of_edges--;
        visited[v]=1;

        //updated the distance[] array
        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[v][i]<distance[i])
            {
                distance[i]=cost[v][i];
                pre[i]=v;
            }
        min_cost=min_cost+cost[u][v];
    }
    return 0;
}

