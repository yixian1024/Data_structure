#include<stdio.h>

main()
{
    int i,j,n;
    int G[100][100],indegree[100],outdegree[100];
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        indegree[i]=outdegree[i]=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d",G[i]+j);
            if(G[i][j]==1)
                indegree[i]++;
        }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
            if(G[i][j]==1)
                outdegree[j]++;
        printf("%d %d %d\n",j+1,outdegree[j],indegree[j]);
    }
}
