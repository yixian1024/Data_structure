#include<stdio.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    int data;
    listpointer rlink,llink;
} listnode;

char invert[50];
listpointer temp,first,end,a,b,x;

void invert_list(listpointer lead)
{
    int i;
    listpointer middle,trail;
    middle=NULL;
    for(i=0;i<3;i++)
    {
        trail=middle;
        middle=lead;
        lead=lead->rlink;
        middle->rlink=trail;
        if(trail!=NULL)
            trail->llink=middle;
    }
    return;
}

main()
{
    int num,i,j,count=0;
    listpointer start,end;

    freopen("3input.txt","r",stdin);

    //input data
    scanf("%d",&num);
    first=(listnode*)malloc(sizeof(*first));
    temp=(listnode*)malloc(sizeof(*temp));
    temp->data=num;
    temp->rlink=NULL;
    first=temp;
    end=first;
    for(i=2,j=0; i<=9; i++)
    {
        scanf("%d",&num);
        temp=(listnode*)malloc(sizeof(*temp));
        temp->data=num;
        temp->rlink=NULL;
        temp->llink=end;
        end->rlink=temp;
        end=temp;
    }
    while(scanf("%d",&invert[count])!=EOF)
        count++;

    //print data
    /*printf("group:");
    for(i=0; i<9; first=first->rlink,i++)
        printf("%d ",first->data);
    printf("\n");
    printf("invert:");
    for(i=0;i<count;i++)
        printf("%d ",invert[i]);*/

    for(i=0;i<count;i++)
    {
        a=first;
        if(invert[i]==1)
            for(j=0;j<3;j++)
                first=first->rlink;
        //mark a b at invert group's start and end
        for(j=0;j<3*(invert[j]-1);j++)
            a=a->rlink;
        b=a;
        for(j=0;j<2;j++)
            b=b->rlink;
        //link gap
        if(invert[i]!=1)
            a->llink=b->rlink;
        //invert group
        invert_list(a);
        end->rlink=b;
        b->llink=end;
        end=a;
        a->rlink=NULL;
        printf("first:%d\n",first->data);
        a=first;
        for(j=0; j<8; end=end->llink,j++)
            printf("%d ",end->data);
        printf("%d",a->data);
        if(i!=count-1)printf("\n");
    }
}
