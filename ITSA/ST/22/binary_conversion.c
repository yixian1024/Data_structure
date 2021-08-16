#include<stdio.h>
#include<string.h>

int main()
{
    char num1[10],num2[10];
    int sum1,sum2,i,ncase,len,bi,ans;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%s%s",num1,num2);
        sum1=sum2=0;
        len=strlen(num1);
        bi=1;
        for(i=len-1;i>=0;i--)
        {
            if(num1[i]=='1')
                sum1+=bi;
            bi*=2;
        }
        //printf("sum1:%d\n",sum1);
        len=strlen(num2);
        bi=1;
        for(i=len-1;i>=0;i--)
        {
            if(num2[i]=='1')
                sum2+=bi;
            bi*=2;
        }
        //printf("sum2:%d\n",sum2);
        ans=sum1+sum2;
        printf("%d\n",ans);
    }
    return 0;
}
