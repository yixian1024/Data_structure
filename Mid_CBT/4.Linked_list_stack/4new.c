#include<stdio.h>
#include<string.h>
#define MAXSTACK 10

typedef struct stack *stackpointer;
typedef struct stack
{
    int data;
    stackpointer link;
};
stackpointer top,block;
int count,stack[20];

void pop(void)
{
    top=top->link;
    count--;
    return;
}

void push(int x)
{
    block=(stackpointer*)malloc(sizeof(*block));
    block->data=x;
    block->link=top;
    top=block;
    count++;
    return;
}

main()
{
    char temp[10],instruction[10];
    int i,j,num;
    //freopen("4input.txt","r",stdin);
    count=0;
    while(gets(temp)!=NULL)
    {
        sscanf(temp,"%s",instruction);
        if(strcmp(instruction,"Pop")==0)
            pop();
        else
        {
            sscanf(temp,"%s%d",instruction,&num);
            push(num);
        }
    }
    printf("%d\n",count);
    for(i=0;i<count;i++)
    {
        stack[i]=top->data;
        top=top->link;
    }
    for(i=count-1;i>0;i--)
        printf("%d ",stack[i]);
    printf("%d",stack[0]);
}
