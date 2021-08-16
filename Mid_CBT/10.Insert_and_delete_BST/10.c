#include<stdio.h>
#include<string.h>

typedef struct node *treepointer;
typedef struct node
{
    int data;
    treepointer leftchild,rightchild;
} node;

void insert(int x,treepointer ptr)
{
    treepointer trail;
    while(1)
    {
        trail=ptr;
        if(x>ptr->data)
        {
            ptr=ptr->rightchild;
            if(ptr==NULL)
            {
                ptr=(node*)malloc(sizeof(*ptr));
                trail->rightchild=ptr;
                ptr->data=x;
                ptr->rightchild=NULL;
                ptr->leftchild=NULL;
                return;
            }
        }
        else
        {
            ptr=ptr->leftchild;
            if(ptr==NULL)
            {
                ptr=(node*)malloc(sizeof(*ptr));
                trail->leftchild=ptr;
                ptr->data=x;
                ptr->rightchild=NULL;
                ptr->leftchild=NULL;
                return;
            }
        }

    }
}

void del(int x,treepointer ptr)
{
    treepointer trail;
    while(1)
    {
        if(x>ptr->data)
        {
            trail=ptr;
            ptr=ptr->rightchild;
            if(ptr->data==x)
            {
                trail->rightchild=ptr->rightchild;
                return;
            }
        }
        else
        {
            trail=ptr;
            ptr=ptr->leftchild;
            if(ptr->data==x)
            {
                trail->leftchild=ptr->leftchild;
                return;
            }
        }

    }

}

main()
{
    int a,n,front,end;
    char string[50];
    treepointer temp,root,x,ptr,queue[100];
    //freopen("10input.txt","r",stdin);
    root=(node*)malloc(sizeof(*root));
    root=NULL;
    n=0;
    while(scanf("%d",&a)!=NULL)
    {
        n++;
        //printf("a%d\n",a);
        temp=(node*)malloc(sizeof(*temp));
        temp->data=a;
        temp->rightchild=NULL;
        temp->leftchild=NULL;
        if(!root)
        {
            root=temp;
            continue;
        }
        for(x=root; ;)
        {
            ptr=x;
            //printf("x%d\n",x->data);
            if(a>x->data)
            {
                x=x->rightchild;
                if(x==NULL)
                {
                    ptr->rightchild=temp;
                    break;
                }
            }
            else if(a<x->data)
            {
                x=x->leftchild;
                if(x==NULL)
                {
                    ptr->leftchild=temp;
                    break;
                }
            }
        }
    }
    while(gets(string)!=NULL)
    {
        //printf("%s\n",string);
        if(string[0]=='i')
        {
            sscanf(string,"insert(%d)",&a);
            //printf("%d\n",a);
            insert(a,root);
        }
        if(string[0]=='d')
        {
            sscanf(string,"delete(%d)",&a);
            //printf("%d\n",a);
            del(a,root);
        }
    }
    /*for(x=root; x!=NULL; x=x->leftchild)
        printf("x%d\n",x->data);*/
    queue[0]=root;
    front=0;
    end=0;
    while(1)
    {
        ptr=queue[front];
        front++;
        if(ptr)
        {
            printf("%d ",ptr->data);
            end++;
            queue[end]=ptr->leftchild;
            end++;
            queue[end]=ptr->rightchild;
        }
        if(front==end)
        {

            printf("%d",queue[end]->data);
            break;
        }
    }
}
