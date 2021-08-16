#include<stdio.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    int data;
    listpointer link;
} listnode;

listpointer list[100],temp,ptr;

main()
{
    int n,i,j,k;
    int G[100][100],count[100],mark[100];
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            scanf("%d",G[i]+j);
        count[i]=mark[i]=0;
    }
    //build predecessor list
    for(j=0; j<n; j++)
    {
        list[j]=(listnode*)malloc(sizeof(*list[j]));
        ptr=(listnode*)malloc(sizeof(*ptr));
        for(i=0; i<n; i++)
            if(G[i][j]==1)
            {
                temp=(listnode*)malloc(sizeof(*temp));
                temp->data=i;
                if(list[j]=NULL)
                {
                    list[j]=temp;
                    ptr=list[j];
                }
                else
                {
                    ptr->link=temp;
                }
                ptr=ptr->link;
                count[j]++;
            }
    }
    while(n)
    {
        i=0;
        if(count[i]==0&&!mark[i])
        {
            n--;
            printf("%d ",i);
            mark[i]=1;
            //delete predecessor
            for(j=0; j<n; j++)
            {
                ptr=temp=list[j];
                while(!ptr)
                {
                    if(ptr->data==i)
                    {
                        temp->link=ptr->link;
                        count[j]--;
                        break;
                    }
                    temp=ptr;
                    ptr=ptr->link;
                }
            }
        }
        i++;
    }
}



