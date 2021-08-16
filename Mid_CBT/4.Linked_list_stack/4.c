#include<stdio.h>
#include<string.h>

int stack[100],count;

void pop(void)
{
    count--;
    return;
}

void push(int x)
{
    stack[count++]=x;
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
    for(i=0;i<count-1;i++)
        printf("%d ",stack[i]);
    printf("%d",stack[count-1]);
}
