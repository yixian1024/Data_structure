#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int u,v,cost;
} Node;

int cmp(const void *a,const void *b)
{
    return (((Node*)a)->cost) - (((Node*)b)->cost);
}

Node node[100];

main()
{
    int i,j,n,m,mark[100],ans[100];
    int G[100][100];
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0; i<n; i++)
        mark[i]=0;
    m=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&G[i][j]);
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++)
            if(G[i][j]!=0)
            {
                node[m].u=i;
                node[m].v=j;
                node[m].cost=G[i][j];
                m++;
            }
    qsort(node,m,sizeof(Node),cmp);
    j=0;
    for(i=0;i<m;i++)
        if(!mark[node[i].u]||!mark[node[i].v])
        {
            mark[node[i].u]=mark[node[i].v]=1;
            ans[j]=i;
            j++;

        }

    for(i=0; i<j; i++)
        printf("%d %d %d\n",node[ans[i]].u+1,node[ans[i]].v+1,node[ans[i]].cost);

    }
