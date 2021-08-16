#include<stdio.h>
#include<stdlib.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    int data;
    listpointer link;
}listnode;

listpointer front,end,temp;
int count,flag=0;


void enqueue(int x)
{
    //printf("enqueue:%d\n",x);
    if(count==5)
    {
        if(flag!=0)printf("\n");
        printf("The queue is full.");
        flag++;
        return;
    }
    temp=(listnode*)malloc(sizeof(*temp));
    temp->data=x;
    if(count==0)
        front=temp;
    temp->link=front;
    end->link=temp;
    end=temp;
    count++;
    return;
}

void dequeue(void)
{
    //printf("dequeue\n");
    front=front->link;
    end->link=front;
    count--;
    return;
}

main()
{
    int option,i,num;
    //freopen("8input-2.txt","r",stdin);
    count=0;
    front=(listnode*)malloc(sizeof(*front));
    end=(listnode*)malloc(sizeof(*end));
    while(scanf("%d",&option)!=EOF)
    {
        switch(option)
        {
        //enqueue
        case 1:
            {
                scanf("%d",&num);
                enqueue(num);
            }
            break;
        //dequeue
        case 2:
            dequeue();
            break;
        //output queue
        case 3:
            {
                if(flag!=0)printf("\n");
                if(count==0)printf("The queue is empty.");
                else
                {
                    temp=front;
                    printf("%d",temp->data);
                    temp=temp->link;
                    for(;temp!=front;temp=temp->link)
                        printf(" %d",temp->data);
                }
                flag++;

            }
            break;
        }
    }

}
