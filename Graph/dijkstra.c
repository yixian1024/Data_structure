#include<stdio.h>
#define INFINITY 999999
#define MAX 100

int n;
int G[MAX][MAX],distance[MAX];


void dijkstra(int startnode)
{

    int cost[MAX][MAX],pre[MAX];
    int visited[MAX],count,min,next,i,j;

    //stores the predecessor of each node
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    //initialize
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pre[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        min=INFINITY;

        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<min&&!visited[i])
            {
                min=distance[i];
                next=i;
            }

            //check if a better path exists through nextnode
            visited[next]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(min+cost[next][i]<distance[i])
                    {
                        distance[i]=min+cost[next][i];
                        pre[i]=next;
                    }
        count++;
    }
}
int main(void)
{
    int i,j,start,end;
    FILE *output;

    //input
    freopen("1input.txt","r",stdin);
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    output=fopen("1output.txt","w");
    while(1)
    {
        printf("If you want to end the execution,please enter -1 -1\n");
        printf("Enter the vertices<start end>:");
        scanf("%d%d",&start,&end);
        if(start==-1||end==-1)return 0;
        dijkstra(start-1);
        if(distance[end-1]==INFINITY)distance[end-1]=-1;
        printf("The cost from start to end is : %d\n\n",distance[end-1]);
        //print in the file
        fprintf(output,"Enter the vertices<start end>:%d %d\n",start,end);
        fprintf(output,"The cost from start to end is : %d\n\n",distance[end-1]);

    }

}

