#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef struct Stuff
{
    float max,average;
    char name[30];
}Stuff;

int main(void)
{
    char temp[100];
    int n,i,mark,count,flag;
    float cost,ans=0;
    Stuff product[1000];

    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    mark=n;
    count=0;
    while(mark--)
    {
        scanf("%s %f",temp,&cost);
        i=0;
        //printf("%s %f\n",temp,cost);
        flag=0;
        for(i=0;i<count;i++)
            if(strcmp(product[i].name,temp)==0)
            {
                if(cost>product[i].max)
                    product[i].max=cost;
                flag=1;
            }
        if(flag==0)
        {
            product[count].max=cost;
            strcpy(product[count].name,temp);
            count++;
        }
    }
    for(i=0;i<count;i++)
    {
        //printf("print:%s %.2f\n",product[i].name,product[i].max);
        ans+=product[i].max;
    }
    printf("%d\n",(int)ans);
    return 0;
}

