#include<stdio.h>

typedef struct tree
{
    int leftchild,rightchild,level;
}tree;

int k[100];
tree node[100];
int count,dest,ans,n;

void bfs(int parent)
{
    count++;
    if(parent==-1)return;
    if(parent==dest)
    {
        ans=count;
        printf("%d\n",ans);
        return 0;
    }
    if(parent-k[parent]>0)
        node[parent].leftchild=parent-k[parent];
    else
        node[parent].leftchild=-1;
    if(parent+k[parent]<=n)
        node[parent].rightchild=parent+k[parent];
    else
        node[parent].rightchild=-1;
    if(node[parent].leftchild!=-1)
        bfs(node[parent].leftchild);
    if(node[parent].rightchild!=-1)
        bfs(node[parent].rightchild);

}

main()
{
    int i,j,a;
    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&a,&dest);
    for(i=1;i<=n;i++)
        scanf("%d",&k[i]);
    count=0;
    bfs(a);
    printf("%d\n",ans);

}
