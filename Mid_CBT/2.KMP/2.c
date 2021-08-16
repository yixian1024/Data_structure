#include<stdio.h>
#include<string.h>
#include<ctype.h>

char pat[10],string[50],failure[50];
int slen,plen;

void fail(void)
{
    int i,j;
    failure[0]=-1;
    for(j=1;j<plen;j++)
    {
        i=failure[j-1];
        while(pat[j]!=pat[i+1]&&i>=0)
            i=failure[i];
        if(pat[j]==pat[i+1])
            failure[j]=i+1;
        else
            failure[j]=-1;
    }
    printf("F : ");
    for(i=0;i<plen-1;i++)
        printf("%d ",failure[i]);
    printf("%d\n",failure[plen-1]);
}

int match(void)
{
    int start=-1;
    int i,j;
    i=j=0;
    while(i<slen&&j<plen)
    {
        if(string[i]==pat[j]&&start==-1)
        {
            start=i;
            i++;
            j++;
        }
        if(string[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
            i++;
        else
        {
            j=failure[j-1]+1;
            start=i-j;
        }
        //printf("start%d\n",start);
    }
    return start;
}

main()
{
    int i,j,start,end,count;
    char temp[50];
    //freopen("2input.txt","r",stdin);

    //input data
    gets(temp);
    for(i=3,j=0;i<strlen(temp);i++)
    {
        if(isalpha(temp[i]))
        {
            string[j]=temp[i];
            j++;
        }
    }
    gets(temp);
    for(i=3,j=0;i<strlen(temp);i++)
    {
        if(isalpha(temp[i]))
        {
            pat[j]=temp[i];
            j++;
        }
    }
    slen=strlen(string);
    plen=strlen(pat);

    //print out T P
    /*for(i=0;i<slen;i++)
        printf("%c ",string[i]);
    printf("\n");
    for(i=0;i<plen;i++)
        printf("%c ",pat[i]);
    printf("\n");*/

    //fail and match
    fail();
    start=match();
    end=start+plen-1;
    if(start==-1)
        printf("Not found");
    else
        printf("Yes,%d,%d",start,end);
}
