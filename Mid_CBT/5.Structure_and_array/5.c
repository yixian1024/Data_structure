#include<stdio.h>
#include<string.h>

typedef struct
{
    char name[50],location[50],open[50];
    int value;
} Nightmarket;

Nightmarket market[100];
int count;

void highest_value(void)
{
    int i,max,index;
    max=-1;
    for(i=0; i<count; i++)
        if(market[i].value>max)
        {
            max=market[i].value;
            index=i;
        }
    printf("�����̰����]���G%s\n",market[index].name);
    return;
}
void open_on_wednesday(void)
{
    int i,j,flag=0;
    printf("�P���T���}���]���G");
    for(i=0; i<count; i++)
        for(j=0; j<strlen(market[i].open); j++)
            if(market[i].open[j]=='3')
            {
                if(flag==0)
                    printf("%s",market[i].name);
                else
                    printf("�B%s",market[i].name);
                    flag++;
            }
    printf("\n");
    return;
}
void in_taichung(void)
{
    int i,flag=0;
    printf("�x�����]���G");
    for(i=0;i<count;i++)
        if(strcmp(market[i].location,"�x����")==0)
            {
                if(flag==0)
                    printf("%s",market[i].name);
                else
                    printf("�B%s",market[i].name);
                    flag++;
            }
}
main()
{
    char temp[50];
    int i,j;
    freopen("5input.txt","r",stdin);
    count=0;
    while(gets(temp)!=NULL)
    {
        for(i=0; i<strlen(temp); i++)
            if(temp[i]==',')
                temp[i]=' ';
        sscanf(temp,"%s%s%d%s\n",market[count].name,market[count].open,&market[count].value,market[count].location);
        //printf("%s,%s,%d,%s\n",market[count].name,market[count].open,market[count].value,market[count].location);
        count++;
    }
    highest_value();
    open_on_wednesday();
    in_taichung();
}
