#include<stdio.h>

main()
{
    int i,j,k,n;
    int G[100][100],temp[100][100];
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d",G[i]+j);
            temp[i][j]=G[i][j];
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(G[i][j]&&G[j][k])
                    temp[i][k]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
            printf("%d ",temp[i][j]);
        printf("%d\n",temp[i][n-1]);
    }
}
