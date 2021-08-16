#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
typedef struct edge
{
    int a,b,w;
}edge;

edge e[100];
int n,G[MAX][MAX],mark[MAX];
int queue[MAX],front,rear;
FILE *output;

void insert_queue(int vertex)
{
        if(front == -1)
            front++;
        rear++;
        queue[rear] = vertex ;
}

int isEmpty_queue()
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int x;
    x = queue[front];
    front++;
    return x;
}
void BFS(int v)
{
    int i,level,count;
    front=rear=-1;
    insert_queue(v);
    level=0;
    count=1;
    insert_queue(-1);
    while(!isEmpty_queue())
    {
        v = delete_queue();
        if(v==-1)
        {
            level++;
            insert_queue(-1);
            continue;
        }
        if(!mark[v])
        {
            printf("%d %d\n",level,v+1);
            fprintf(output,"%d %d\n",level,v+1);

        }
        mark[v]=1;
        for(i=0; i<n; i++)
            if(G[v][i]==1&&!mark[i])
                insert_queue(i);
    }
    printf("\n");
}

int main()
{
    int i,j,v,temp,max;
    freopen("3input.txt","r",stdin);
    scanf("%d",&n);
    printf("Please enter the number of adjacency matrix:\n");
    printf("Please enter the adjacency matrix:\n");
    max=v=-1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        scanf("%d",&temp);
        if(i==j)
            G[i][j]=0;
        else if(temp==0)
            G[i][j]=1;
        else
            G[i][j]=temp;
        if(temp>max)
        {
            max=temp;
            if(i>v)v=i;
            if(j>v)v=j;
        }
    }
    printf("start from:%d\n",v+1);
    for(i=0; i<n; i++)
        mark[i]=0;
    output=fopen("3output.txt","w");
    fprintf(output,"Level Name\n");
    BFS(v);
    fclose(output);
    return 0;
}
