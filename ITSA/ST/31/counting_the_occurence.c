#include<stdio.h>
#include<string.h>

main()
{
    char string[1000];
    int count[1000],i,a,len,ans,max,flag;
    while(gets(string)!=NULL)
    {
        len=strlen(string);
        for(i=0;i<1000;i++)
            count[i]=0;
        max=-1;
        flag=1;
        for(i=0;i<len;i++)
        {
            a=string[i];
            count[a]++;
            if(count[a]>max)
            {
                flag=1;
                max=count[a];
                ans=i;
            }
            else if(count[a]==max)
                flag=0;
        }
        if(flag)
            printf("%c\n",string[ans]);
        else
            printf("None\n");
    }
}
