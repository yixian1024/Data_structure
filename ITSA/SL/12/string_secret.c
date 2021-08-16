#include<stdio.h>
#include<string.h>
#include<ctype.h>

main()
{
    int i,len;
    char string[100000];
    //freopen("in.txt","r",stdin);
    while(fgets(string,100000,stdin)!=NULL)
    {
        len=strlen(string);
        for(i=0;i<len;i++)
        {
            //printf("%c",string[i]);
            if(islower(string[i]))
            {
                string[i]=25-(string[i]-'a')+'a';
                string[i]=toupper(string[i]);
            }
            else if(isupper(string[i]))
            {
                string[i]=25-(string[i]-'A')+'A';
                string[i]=tolower(string[i]);
            }
            else if(isdigit(string[i]))
            {
                if(string[i]=='9')
                    string[i]='0';
                else
                    string[i]++;
            }
        }
        printf("%s",string);
    }
}
