#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    char name[10];
    listpointer link;
}listnode;

listpointer begin,end,temp,trail;

main()
{
    int i,j,len,skip;
    char string[1000],*token,c[5]=",";
    freopen("16input.txt","r",stdin);
    gets(string);
    len=strlen(string);
    token=strtok(string,c);
    while(token!=NULL)
    {
        temp=(listnode*)malloc(sizeof(*temp));
        strcpy(temp->name,token);
        //printf("%s\n",temp->name);
        if(begin==NULL)
        {
            begin=temp;
            end=temp;
            token=strtok(NULL,c);
            continue;
        }
        temp->link=begin;
        end->link=temp;
        end=temp;
        token=strtok(NULL,c);
    }
    scanf("%d",&skip);
    temp=begin;
    while(temp->link!=temp)
    {
        for(i=0;i<skip-1;i++)
        {
            trail=temp;
            temp=temp->link;
        }
        printf("%s is killed.\n",temp->name);
        temp=temp->link;
        trail->link=temp;
    }
    printf("%s is survived.",temp->name);

}
