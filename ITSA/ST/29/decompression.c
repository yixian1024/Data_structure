#include<stdio.h>
#include<ctype.h>

int main()
{
    int num,i,j;
    char s[10500],pair[10500];
    while(scanf("%s",s)!=EOF)
    {
        i=0;
        while(s[i]!=0)
        {
            num=0;
            for(;isdigit(s[i]);i++)num=num*10+s[i]-'0';
            for(j=0;isalpha(s[i]);i++,j++)pair[j]=s[i];
            pair[j]=0;
            for(j=0;j<num;j++)printf("%s",pair);
        }
        printf("\n");
    }
    return 0;
}
