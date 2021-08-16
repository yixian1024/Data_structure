#include<stdio.h>

typedef struct node *treepointer;
typedef struct node
{
    int data;
    treepointer leftchild,rightchild;
} node;

int n,count;

void inorder(treepointer ptr)
{
    if(ptr)
    {
        inorder(ptr->leftchild);
        count++;
        if(count==n)
        {
            printf("%d\n",ptr->data);
            return;
        }
        printf("%d ",ptr->data);
        inorder(ptr->rightchild);
    }
    return;
}

void postorder(treepointer ptr)
{
    //printf("postorder:\n");
    if(ptr)
    {
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        count++;
        if(count==n)
        {
            printf("%d\n",ptr->data);
            return;
        }
        printf("%d ",ptr->data);
    }
    return;
}

void preorder(treepointer ptr)
{
   // printf("preorder:\n");
    if(ptr)
    {
        count++;
        if(count==n)
        {
            printf("%d",ptr->data);
            return;
        }
        printf("%d ",ptr->data);
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
    return;
}

main()
{
    int a;
    treepointer temp,root,x,ptr;
    freopen("9input.txt","r",stdin);
    root=(node*)malloc(sizeof(*root));
    root=NULL;
    n=0;
    while(scanf("%d",&a)!=EOF)
    {
        n++;
        temp=(node*)malloc(sizeof(*temp));
        temp->data=a;
        temp->rightchild=NULL;
        temp->leftchild=NULL;
        if(!root)
        {
            root=temp;
            ptr=temp;
            continue;
        }
        for(x=root; ;)
        {
            ptr=x;
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
    count=0;
    inorder(root);
    count=0;
    postorder(root);
    count=0;
    preorder(root);
    return 0;
}
