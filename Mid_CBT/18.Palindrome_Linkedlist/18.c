#include<stdio.h>
#include<string.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    char word;
    listpointer rlink,llink;
}listnode;

listpointer front,end,temp;

main()
{
    int flag=0,len,i;
    char string[100];
    //freopen("18input.txt","r",stdin);
    while(gets(string)!=NULL)
    {
        len=strlen(string);
        for(i=0;i<len;i++)
        {
            temp=(listnode*)malloc(sizeof(*temp));
            temp->word=string[i];
            if(front==NULL)
            {
                front=temp;
                end=front;
                continue;
            }
            end->rlink=temp;
            temp->llink=end;
            end=temp;
        }
        if(flag!=0)printf("\n");
        for(temp=front;temp!=end;temp=temp->rlink)
            printf("%c",temp->word);
        printf("%c",end->word);
        temp=end;
        while(temp->word==end->word)
            temp=temp->llink;
        for(;temp!=front;temp=temp->llink)
            printf("%c",temp->word);
        printf("%c",front->word);
        front=end=NULL;
        flag++;
    }
}
