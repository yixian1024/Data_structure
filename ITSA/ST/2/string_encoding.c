#include<stdio.h>
#include<string.h>

main()
{
    char string[100];
    int ans,len,i;
    while(gets(string)!=NULL)
    {
        ans=0;
        len=strlen(string);
        for(i=0;i<len;i++)
            ans=ans*26+string[i]-'A'+1;
        printf("%d\n",ans);
    }
}
