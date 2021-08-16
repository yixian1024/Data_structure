#include<stdio.h>
#include<string.h>

char stack[10];
int top;

void push(char x)
{
    stack[top]=x;
    top++;
    return;
}

void pop(void)
{
    top--;
    printf("%c",stack[top]);
    return;
}

main()
{
    int M,n,i,j,len,flag=0;
    char string[100];
    //freopen("19input.txt","r",stdin);
    while(scanf("%d %s",&M,string)!=EOF)
    {
        if(flag!=0)printf("\n");
        //printf("input:%d %s\n",M,string);
        len=strlen(string);
        if(M>len)
        {
            printf("%s",string);
            flag++;
            continue;
        }
        for(i=0; i<len; i+=3)
        {
            for(j=0; j<3; j++)
                push(string[i+j]);
            for(j=0; j<3; j++)
                pop();
            top=0;
        }
        for(i=0;i<=len;i++)
            string[i]=0;
        flag++;
    }
    return 0;
}
