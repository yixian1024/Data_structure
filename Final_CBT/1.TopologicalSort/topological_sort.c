#include<stdio.h>

main()
{
    int n,i,j,k,m,flag;
    int G[100][100],count[100],mark[100],num[100];
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(j=0; j<n; j++)
        count[j]=-1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",G[i]+j);
            if(G[i][j]==1)
                count[j]++;
        }
        mark[i]=0;
    }
    m=0;
    for(j=0; j<n; j++)
    {
        flag=0;
        if(count[j]!=-1)
            count[j]++;
        else
        {
            for(i=0;i<n;i++)
                if(G[j][i]==1)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
            {
                mark[j]=1;
                m++;
            }
            else
                count[j]++;
        }
    }
    k=0;
    while(!flag)
    {
        for(i=0; i<n; i++)
        {
            if(count[i]==0&&!mark[i])
            {
                num[k]=i;
                k++;
                mark[i]=1;
                for(j=0; j<n; j++)
                {
                    if(G[i][j]==1)
                    {
                        G[i][j]=0;
                        count[j]--;
                    }
                }
                i=0;
            }
        }
        flag=1;
        for(j=0; j<n; j++)
            if(!mark[j])
                flag=0;
    }
    for(i=0;i<n-m-1;i++)
    printf("%d ",num[i]+1);
    printf("%d\n",num[n-m-1]+1);
}


