#include<stdio.h>
#include<string.h>
#include<ctype.h>

main()
{
    char string[100];
    int num,len,i,flag;
    while(gets(string)!=NULL)
    {
        num=0;
        flag=0;
        len=strlen(string);
        for(i=0;i<len;i++)
            if(isdigit(string[i]))
            {
                num=(string[i]-'0')+num*10;
                flag=1;
            }
        if(flag==0)
            printf("-1\n");
        else
            printf("%d\n",num);
    }
    return 0;
}
