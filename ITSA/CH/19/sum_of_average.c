#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef struct Stuff
{
    int m;
    float sum,average;
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
    for(i=0;i<50;i++)
    {
        product[i].sum=0;
        product[i].m=0;
    }
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
                product[i].sum+=cost;
                product[i].m++;
                flag=1;
            }
        if(flag==0)
        {
            product[count].m++;
            product[count].sum+=cost;
            strcpy(product[count].name,temp);
            count++;
        }
    }
    for(i=0;i<count;i++)
    {
        //printf("print:%s %.2f %d\n",product[i].name,product[i].sum,product[i].m);
        ans+=(float)product[i].sum/product[i].m;
    }
    printf("%.2f\n",ans);
    return 0;
}
