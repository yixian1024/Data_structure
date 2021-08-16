#include<stdio.h>
#include<string.h>

int add(char string[])
{
    int len,sum,i;
    len=strlen(string);
    sum=0;
    for(i=0;i<len;i++)
    {
        sum+=string[i]-'0';
        if(sum>=10)
            sum=sum/10+sum%10;
    }
    return sum;
}

main()
{
    char string[100];
    int sum,flag=0;
    //freopen("15input.txt","r",stdin);
    while(gets(string)!=NULL)
    {
        sum=add(string);
        if(flag!=0)
            printf("\n");
        printf("%d",sum);
        flag++;
    }
}
