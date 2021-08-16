#include<stdio.h>

typedef struct polylist *polypointer;
typedef struct polylist
{
    float coef;
    int expo;
    polypointer link;
} polylist;

polypointer start[5],end[5],a,b,temp;
int mark;

void add(void)
{
    mark++;
    a=start[0];
    b=start[1];
    while(1)
    {
        if(a->expo==b->expo)
        {
            temp=(polylist*)malloc(sizeof(*temp));
            temp->coef=a->coef+b->coef;
            temp->expo=a->expo;
            temp->link=NULL;
            if(start[mark]==NULL)
            {
                end[mark]=temp;
                start[mark]=temp;
                a=a->link;
                b=b->link;
                continue;
            }
            end[mark]->link=temp;
            end[mark]=temp;
            a=a->link;
            b=b->link;
        }
        else if(a->expo>b->expo)
        {
            temp=(polylist*)malloc(sizeof(*temp));
            temp->coef=a->coef;
            temp->expo=a->expo;
            temp->link=NULL;
            if(start[mark]==NULL)
            {
                end[mark]=temp;
                start[mark]=temp;
                a=a->link;
                b=b->link;
                continue;
            }
            end[mark]->link=temp;
            end[mark]=temp;
            a=a->link;
        }
        else
        {
            temp=(polylist*)malloc(sizeof(*temp));
            temp->coef=b->coef;
            temp->expo=b->expo;
            temp->link=NULL;
            if(start[mark]==NULL)
            {
                end[mark]=temp;
                start[mark]=temp;
                a=a->link;
                b=b->link;
                continue;
            }
            end[mark]->link=temp;
            end[mark]=temp;
            b=b->link;
        }
        if(a==NULL&&b==NULL)break;
    }

}

void subtract(void)
{
    mark++;
    a=start[0];
    b=start[1];
    while(1)
    {
        if(a->expo==b->expo)
        {
            temp=(polylist*)malloc(sizeof(*temp));
            temp->coef=a->coef-b->coef;
            temp->expo=a->expo;
            temp->link=NULL;
            if(start[mark]==NULL)
            {
                end[mark]=temp;
                start[mark]=temp;
                continue;
            }
            end[mark]->link=temp;
            end[mark]=temp;
            a=a->link;
            b=b->link;
        }
        else if(a->expo>b->expo)
        {
            temp=(polylist*)malloc(sizeof(*temp));
            temp->coef=a->coef;
            temp->expo=a->expo;
            temp->link=NULL;
            if(start[mark]==NULL)
            {
                end[mark]=temp;
                start[mark]=temp;
                continue;
            }
            end[mark]->link=temp;
            end[mark]=temp;
            a=a->link;
        }
        else
        {
            temp=(polylist*)malloc(sizeof(*temp));
            temp->coef=-b->coef;
            temp->expo=b->expo;
            temp->link=NULL;
            if(start[mark]==NULL)
            {
                end[mark]=temp;
                start[mark]=temp;
                continue;
            }
            end[mark]->link=temp;
            end[mark]=temp;
            b=b->link;
        }
        if(a==NULL&&b==NULL)break;
    }

}

void mutiply(void)
{

}


main()
{
    int i,flag=0;
    char string[10];
    freopen("14input.txt","r",stdin);
    mark=0;
    while(gets(string)!=NULL)
    {
        if(string[0]==':')
        {
            mark++;
            continue;
        }
        temp=(polylist*)malloc(sizeof(*temp));
        sscanf(string,"%f%d",&temp->coef,&temp->expo);
        //printf("coef:%.1f  expo:%d  mark:%d\n",temp->coef,temp->expo,mark);
        temp->link=NULL;
        if(start[mark]==NULL)
        {
            start[mark]=temp;
            end[mark]=temp;
            continue;
        }
        end[mark]->link=temp;
        end[mark]=temp;
    }
    add();
    subtract();
    mutiply();
    for(i=0; i<=mark; i++)
    {
        a=start[i];
        if(flag!=0)printf("\n");
        printf("%c(x)=",i+'A');
        printf("%.1fx^%d",a->coef,a->expo);
        a=a->link;
        for(; a!=end[i]; a=a->link)
        {
            if(a->coef>0)
                printf("+");
            printf("%.1fx^%d",a->coef,a->expo);
        }
        if(a->coef>0)
            printf("+");
        printf("%.1f",end[i]->coef);
        flag++;
    }
}
