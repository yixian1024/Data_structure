#include<stdio.h>
#include<stdlib.h>

typedef struct treenode *treepointer;
typedef struct treenode
{
    int data,coin;
    treepointer right,left;
} treenode;

treepointer ptr,root,queue[100000];
int front,end;
FILE *file,*result;

void insert(treepointer temp)
{
    treepointer trail;
    ptr=root;
    while(1)
    {
        trail=ptr;
        if(temp->data>ptr->data)
        {
            ptr=ptr->right;
            if(ptr==NULL)
            {
                trail->right=temp;
                return;
            }
        }
        else if(temp->data<ptr->data)
        {
            ptr=ptr->left;
            if(ptr==NULL)
            {
                trail->left=temp;
                return;
            }
        }
    }
}

void del(int x)
{
    treepointer trail;
    ptr=root;
    while(ptr)
    {
       if(x>ptr->data)
       {
            trail=ptr;
            ptr=ptr->right;
           if(x==ptr->data)
           {
               trail=ptr->right;
               printf("trail%d\n",ptr->data);
               return;
           }
       }
       else
       {
            trail=ptr;
            ptr=ptr->left;
           if(x==ptr->data)
           {
               trail=ptr->right;
               printf("trail%d\n",ptr->data);
               return;
           }
       }
    }
    printf("No such a number!\n");
    return;
}

int search(int x)
{
    ptr=root;
    while(ptr)
    {
       if(x==ptr->data)return 1;
       if(x>ptr->data)
            ptr=ptr->right;
       else
            ptr=ptr->left;
    }
    return 0;
}

void inorder(treepointer ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
    return;
}

void enqueue(treepointer temp)
{
    end++;
    queue[end]=temp;
}

treepointer dequeue(void)
{
    if(front>end)return NULL;
    front++;
    return queue[front-1];
}

void levelorder(treepointer ptr)
{
    if(!ptr)return;
    enqueue(ptr);
    while(1)
    {
        ptr=dequeue();
        if(ptr)
        {
            printf("%d ",ptr->data);
            if(ptr->left)
                enqueue(ptr->left);
            if(ptr->right)
                enqueue(ptr->right);
        }
        else
        {
            printf("\n");
            return;
        }
    }
}

int hunt(int hunter)
{
    int treasure;
    treepointer trail;
    ptr=root;
    treasure=0;
    while(1)
    {
        trail=ptr;
        fprintf(result,"node:%d collect %d coins\n",ptr->data,ptr->coin);
        if(hunter>ptr->data)
        {
            treasure+=ptr->coin;
            ptr=ptr->right;
            if(ptr==NULL||hunter==ptr->data)
            {
                return treasure;
            }
        }
        else if(hunter<ptr->data)
        {
            treasure+=ptr->coin;
            ptr=ptr->left;
            if(ptr==NULL||hunter==ptr->data)
            {
                return treasure;
            }
        }
    }
}

main()
{
    int a,b,option,flag,num,atotal,btotal;
    treepointer temp;
    while(1)
    {
        //choose execution
        printf("Which option do you want to execute.\n");
        printf("0.Quit.\n");
        printf("1.Implement a binary search tree.\n");
        printf("2.Treasure hunter.\n");
        scanf("%d",&option);
        if(option==0)
        {
            root=NULL;
            return 0;
        }
        switch(option)
        {
            //binary search tree
        case 1:
            {
                while(1)
                {
                    printf("(0)return\n");
                    printf("(1)insert\n");
                    printf("(2)delete\n");
                    printf("(3)search\n");
                    printf("(4)inorder\n");
                    printf("(5)levelorder\n");

                    scanf("%d",&flag);
                    if(flag==0)
                    {
                        root=NULL;
                        break;
                    }
                    switch(flag)
                    {
                        //insert
                    case 1:
                        {
                            printf("If you want quit, enter -1.\n");
                            while(1)
                            {
                                printf("Enter a number to insert:\n");
                                scanf("%d",&num);
                                if(num==-1)
                                    break;
                                temp=(treenode*)malloc(sizeof(*temp));
                                temp->data=num;
                                temp->right=temp->left=NULL;
                                if(!root)
                                {
                                    //root=(treenode*)malloc(sizeof(*root));
                                    root=temp;
                                    continue;
                                }
                                insert(temp);
                            }
                        }
                        continue;
                        //delete
                    case 2:
                        {
                            printf("Enter a number to delete:\n");
                            scanf("%d",&num);
                            del(num);
                        }
                        continue;
                        //search
                    case 3:
                        {
                            printf("Enter a number to search:\n");
                            scanf("%d",&num);
                            if(search(num))
                                printf("Have such node.\n");
                            else
                                printf("Didn't have such node.\n");
                        }
                        continue;
                        //inorder
                    case 4:
                        {
                            printf("\nInorder search:\n");
                            inorder(root);
                            printf("\n");

                        }
                        continue;
                        //levelorder
                    case 5:
                        {
                            front=0;
                            end=-1;
                            printf("\nLevel order search:\n");
                            levelorder(root);
                        }
                        continue;
                    }

                }
            }
            continue;
            //treasure hunter
        case 2:
            {
                //input data
                file=fopen("test.txt","r");
                result=fopen("result.txt","w");
                while(fscanf(file,"%d,%d",&a,&b)!=EOF)
                {
                    printf("%d %d\n",a,b);
                    if(search(a))
                    {
                        printf("The number have exist.\n");
                        continue;
                    }
                    temp=(treenode*)malloc(sizeof(*temp));
                    temp->data=a;
                    temp->coin=b;
                    temp->right=temp->left=NULL;
                    if(!root)
                    {
                        //root=(treenode*)malloc(sizeof(*root));
                        root=temp;
                        continue;
                    }
                    //printf("temp:%d %d",temp->data,temp->coin);
                    insert(temp);
                }
                fclose(file);
                while(1)
                {
                    //choose the hunter's id
                    printf("If you want to quit,enter -1.\n");
                    printf("Enter the numbers of the two hunters:\n");
                    scanf("%d%d",&a,&b);
                    if(a==-1||b==-1)break;
                    fprintf(result,"#%d hunter's walking trajectory\n",a);
                    atotal=hunt(a);
                    fprintf(result,"Totally collected %d coins\n\n",atotal);
                    fprintf(result,"#%d hunter's walking trajectory\n",b);
                    btotal=hunt(b);
                    fprintf(result,"Totally collected %d coins\n\n",btotal);
                    if(atotal>btotal)
                        printf("The winner is first hunter.\n");
                    if(atotal<btotal)
                        printf("The winner is second hunter.\n");
                    else
                        printf("They got even coins.\n");
                }
                fclose(result);
            }
            continue;
        }
    }
    return 0;
}
