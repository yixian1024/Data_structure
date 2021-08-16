#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char a[100];
    int i,len,count;
    while(1)
    {
        gets(a);
        if(a[0]=='e'&&a[1]=='n'&&a[2]=='d'&&!isalpha(a[3]))
            return 0;
        len=strlen(a);
        count=0;
        for(i=0;i<len;i++)
        {
            if(isupper(a[i]))
            {
                count+=1;
                tolower(a[i]);
            }
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                count+=5;
            else if(isalpha(a[i]))
                count+=2;
        }
        printf("%d\n",count);
    }
}
