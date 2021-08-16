#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct listnode *listpointer;
typedef struct listnode
{
    int num;
    listpointer llink,rlink;
}listnode;

listpointer temp,first,end,ptr,trail;

void build_list(int num[],int n)
{
    int i;
    //build a list
    temp=(listnode*)malloc(sizeof(*temp));
    first=(listnode*)malloc(sizeof(*first));
    first->num=num[1];
    first->rlink=first;
    end=first;
    first->llink=end;
    for(i=2; i<=n; i++)
    {
        temp=(listnode*)malloc(sizeof(*temp));
        temp->num=num[i];
        temp->rlink=first;
        temp->llink=end;
        end->rlink=temp;
        end=temp;
        first->llink=end;
        end->rlink=first;
    }
    /*for(i=1;i<=2*n;i++,first=first->rlink)
    		printf("%d ",first->num);
    printf("\n");*/
    return;
}

void execution(void)
{
    int i,j,skip,dir,ans;

    //choose skip number and direction
    printf("Enter the number of people to be skipped:");
    scanf("%d",&skip);
    printf("Which direction do you want to choose?(1)Left (2)Right\n");
    scanf("%d",&dir);

    //left execution
    if(dir==1)
    {
        ptr=first;
        while(1)
        {
            for(i=1; i<skip; i++)
            {
                ptr=ptr->llink;
                //printf("%d\n",ptr->num);
            }
            trail=ptr->rlink;
            trail->llink=ptr->llink;
            ptr=ptr->llink;
            ptr->rlink=trail;
            if(ptr->llink==ptr)
            {
                ans=ptr->num;
                break;
            }
        }
    }
    //right execution
    if(dir==2)
    {
        ptr=first;
        while(1)
        {
            for(i=1; i<skip; i++)
            {
                ptr=ptr->rlink;
                //printf("%d\n",ptr->num);
            }
            trail=ptr->llink;
            trail->rlink=ptr->rlink;
            ptr=ptr->rlink;
            ptr->llink=trail;
            if(ptr->rlink==ptr)
            {
                ans=ptr->num;
                break;
            }
        }
    }
    printf("The person who is survive: %d\n",ans);
    return;
}

void read_file(void)
{
    FILE *file;
    char string[1000000];
    int i,j,temp;
    int num[100000];

    //input data
    file=fopen("in.txt","r");
    fscanf(file,"%s",string);
    //printf("%s",string);
    temp=0;
    j=1;
    for(i=0; i<strlen(string); i++)
    {
        if(isdigit(string[i]))
            temp+=temp*10+(string[i]-'0');
        else
        {
            num[j]=temp;
            temp=0;
            j++;
        }
    }
    num[j]=temp;

    //print circular
    for(i=1; i<=j; i++)
        printf("No.%d : %d\n",i,num[i]);
    printf("The people in circular list are:\n");
    for(i=1; i<=j; i++)
        printf("%d ",num[i]);
    printf("\n");

    build_list(num,j);
    execution();
    return;
}

void input_numbers(void)
{
    int i,n;
    int num[100000];
    //add numbers
    printf("How many numbers do you want to  add?");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("No.%d : ",i);
        scanf("%d",num+i);
    }

    //print circular list
    printf("The people in circular list are:\n");
    for(i=1; i<=n; i++)
        printf("%d ",num[i]);
    printf("\n");

    build_list(num,n);
    execution();
    return;
}

main()
{
    int option;
    while(1)
    {
        printf("\n");
        printf("= = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("=   Whitch items do you want to choose?     =\n");
        printf("=   (1)Read numbers from a file.            =\n");
        printf("=   (2)Input new numbers                    =\n");
        printf("=   (0)Quit                                 =\n");
        printf("= = = = = = = = = = = = = = = = = = = = = = =\n");
        scanf("%d",&option);

        //choose the options
        switch(option)
        {
        case 1:
            read_file();
            continue;
        case 2:
            input_numbers();
            continue;
        case 0:
            return 0;

        }

    }

}
