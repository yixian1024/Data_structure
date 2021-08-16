#include<stdio.h>
#include<string.h>
#include<ctype.h>

main()
{
    int count[30],len,i;
    char string[100];
    gets(string);
    len=strlen(string);
    for(i=0; i<26; i++)
        count[i]=0;
    for(i=0; i<len; i++)
        if(isalpha(string[i]))
        {
            string[i]=tolower(string[i]);
            count[string[i]-'a']++;
        }
    for(i=0; i<26; i++)
        printf("%d\n",count[i]);
}
