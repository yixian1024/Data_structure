#include<stdio.h>
#include<string.h>
#include<ctype.h>

char temp[100],element[100];
int top,max;

void push(char x)
{
    top++;
    element[top]=x;
    if(top+1>max)max=top+1;
    return;
}

void pop(void)
{
    printf("%c",element[top]);
    top--;
    return;
}

int cmp(char a,char b)
{
    int t1,t2;
    if(a=='+'||a=='-')
        t1=0;
    else
        t1=1;
    if(b=='+'||b=='-')
        t2=0;
    else
        t2=1;
    if(t1>=t2)
        return 1;
    return 0;
}

main()
{
    int i,j,len;
    freopen("6input-2.txt","r",stdin);
    scanf("%s",temp);
    len=strlen(temp);
    top=max=-1;
    for(i=0;i<len;i++)
    {
        if(isalpha(temp[i]))
            printf("%c",temp[i]);
        else
        {
            while(cmp(element[top],temp[i])&&top!=-1)
                    pop();
            push(temp[i]);
        }
    }
    while(top!=-1)
        pop();
    printf("\n");
    printf("%d",max);
    return 0;
}
