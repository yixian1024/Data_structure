#include<stdio.h>
#include<string.h>

typedef struct Stuff
{
    int m;
    int price[30];
    char name[30];
} Stuff;

int main(void)
{
    char temp[30];
    int n,i,j,mark,count,flag,ans=0,cost;
    Stuff product[1000];

    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(i=0; i<100; i++)
        product[i].m=0;
    mark=n;
    count=0;
    while(mark--)
    {
        scanf("%s%d",temp,&cost);
        i=0;
        //printf("%s %d\n",temp,cost);
        flag=0;
        for(i=0; i<count; i++)
            if(strcmp(product[i].name,temp)==0)
            {
                for(j=0; j<product[i].m; j++)
                    if(product[i].price[j]!=cost)
                    {
                        product[i].price[product[i].m]=cost;
                        //printf("check:%s %d %d\n",product[i].name,product[i].m,product[i].price[product[i].m]);
                        product[i].m++;
                        break;
                    }
                flag=1;
                break;
            }
        if(flag==0)
        {
            product[count].price[product[count].m]=cost;
            strcpy(product[count].name,temp);
            printf("print:%s %d %d\n",product[count].name,product[count].m,product[count].price[product[count].m]);
            product[count].m++;
            count++;
        }
    }
    for(i=0; i<count; i++)
    {
        //printf("end:%s %d\n",product[i].name,product[i].m);
        ans+=product[i].m;
    }
    printf("%d\n",ans);
    return 0;
}
