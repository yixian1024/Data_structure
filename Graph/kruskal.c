#include<stdio.h>
#define MAX 100

typedef struct edge
{
    int a,b,w;
} edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
} edgelist;

int G[MAX][MAX],n;
edgelist spanlist,elist;

int find(int leader[],int x)
{
    //find the lead of the vertex
    return(leader[x]);
}

void union_team(int leader[],int team1,int team2)
{
    int i;
    //union the team
    for(i=0; i<n; i++)
        if(leader[i]==team2)
            leader[i]=team1;
}

void sort(void)
{
    //sort the elist
    int i,j;
    edge temp;
    for(i=1; i<elist.n; i++)
        for(j=0; j<elist.n-1; j++)
            if(elist.data[j].w>elist.data[j+1].w)
            {
                temp=elist.data[j];
                elist.data[j]=elist.data[j+1];
                elist.data[j+1]=temp;
            }
}
void kruskal(void)
{
    int leader[MAX],i,j,team1,team2;
    elist.n=0;

    //make graph in elist
    for(i=1; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(G[i][j]!=0)
            {
                elist.data[elist.n].a=i;
                elist.data[elist.n].b=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }

    sort();

    for(i=0; i<n; i++)
        leader[i]=i;
    spanlist.n=0;
    for(i=0; i<elist.n; i++)
    {
        //find the node's leader
        team1=find(leader,elist.data[i].a);
        team2=find(leader,elist.data[i].b);
        //if two leader are not the same union the two team
        if(team1!=team2)
        {
            spanlist.data[spanlist.n]=elist.data[i];
            spanlist.n++;
            union_team(leader,team1,team2);
        }
        //else their leader are the same discard the edge
    }
}

void main()
{
    int i,j,k,cost=0;
    int G2[MAX][MAX];
    FILE *output;
    freopen("2input.txt","r",stdin);
    printf("Enter number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    //input adjacency list
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&G[i][j]);

    kruskal();

    output=fopen("2output.txt","w");
    fprintf(output,"The edges of Minimum cost spanning tree are:\n");
    for(i=0; i<spanlist.n; i++)
    {
        if(spanlist.data[i].a+1<spanlist.data[i].b+1)
        {
            fprintf(output,"Edge %d:<%d %d> cost:%d\n",i+1,spanlist.data[i].a+1,spanlist.data[i].b+1,spanlist.data[i].w);
            printf("Edge %d:<%d %d> cost:%d\n",i+1,spanlist.data[i].a+1,spanlist.data[i].b+1,spanlist.data[i].w);
        }
        else
        {
            fprintf(output,"Edge %d:<%d %d> cost:%d\n",i+1,spanlist.data[i].b+1,spanlist.data[i].a+1,spanlist.data[i].w);
            printf("Edge %d:<%d %d> cost:%d\n",i+1,spanlist.data[i].b+1,spanlist.data[i].a+1,spanlist.data[i].w);
        }
        cost=cost+spanlist.data[i].w;
    }
    fprintf(output,"Minimum cost = %d\n",cost);
    fclose(output);
    //output the file of BFS
    output=fopen("3input.txt","w");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            G2[i][j]=0;
    for(i=0; i<spanlist.n; i++)
    {
        G2[spanlist.data[i].a][spanlist.data[i].b]=spanlist.data[i].w;
        G2[spanlist.data[i].b][spanlist.data[i].a]=spanlist.data[i].w;
    }

    fprintf(output,"%d\n",n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            fprintf(output,"%d ",G2[i][j]);
        fprintf(output,"\n");
    }
    fclose(output);
}

