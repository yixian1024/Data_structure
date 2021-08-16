#include<stdio.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    int data;
    listpointer link;
} listnode;

int flag;

void ascending(int temp[],int n)
{
    int i,j,a;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(temp[i]>temp[j])
    {
        a=temp[i];
        temp[i]=temp[j];
        temp[j]=a;
    }
    if(flag!=0)
        printf("\n");
    for(i=0;i<n-1;i++)
        printf("%d ",temp[i]);
    printf("%d",temp[n-1]);
    flag++;
    return;
}

main()
{
    int i,j,a,b,n=-1,mark[100],temp[100];
    listpointer x,y,seq[100],top;
    //freopen("12input-2.txt","r",stdin);
    for(i=0; i<100; i++)
        seq[i]=NULL;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        //printf("a:%d b:%d\n",a,b);
        x=(listnode*)malloc(sizeof(*x));
        x->data=b;
        x->link=seq[a];
        seq[a]=x;
        x=(listnode*)malloc(sizeof(*x));
        x->data=a;
        x->link=seq[b];
        seq[b]=x;
        if(a>n)n=a;//seq[]=n
        if(b>n)n=b;
    }
    //printf("n:%d\n",n);
    for(i=0; i<=n; i++)
        mark[i]=0;
    top=NULL;
    flag=0;
    for(i=0,j=0; i<=n; i++)
        if(!mark[i]&&seq[i]!=NULL)
        {
            x=seq[i];
            mark[i]=1;
            temp[j++]=i;
            while(1)
            {
                while(x)
                {
                    if(!mark[x->data])
                    {
                        mark[x->data]=1;
                        y=x->link;
                        x->link=top;
                        top=x;
                        x=y;
                    }
                    else
                        x=x->link;
                }
                if(!top)
                {
                    ascending(temp,j);
                    j=0;
                    break;
                }
                //printf("%d:%d\n",j,temp[j-1]);
                temp[j++]=top->data;
                x=seq[top->data];
                top=top->link;
            }
        }

}
