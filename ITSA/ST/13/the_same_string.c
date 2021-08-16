#include<stdio.h>
#include<string.h>
#include<ctype.h>

main()
{
    int count[30],mark[30],i,n,len,flag;
    char string[5000],sample[5000];
    //initialize
    for(i=0; i<30; i++)
        mark[i]=0;
    gets(sample);
    len=strlen(sample);
    for(i=0; i<len; i++)
    {
        if(isupper(sample[i]))
            mark[sample[i]-'A']++;
        if(islower(sample[i]))
            mark[sample[i]-'a']++;
    }
    scanf("%d",&n);
    n++;
    while(n--)
    {
        for(i=0; i<30; i++)
            count[i]=0;
        gets(string);
        len=strlen(string);
        for(i=0; i<len; i++)
        {
            if(isupper(string[i]))
                count[string[i]-'A']++;
            if(islower(string[i]))
                count[string[i]-'a']++;
        }
        flag=1;
        for(i=0; i<26; i++)
            if(count[i]!=mark[i])
                flag=0;
        if(flag)
            printf("%s\n",string);
    }
    return 0;
}
