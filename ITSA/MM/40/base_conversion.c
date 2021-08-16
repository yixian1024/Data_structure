#include<stdio.h>

int main(void)
{
    int ncase,n,b,ans[100],i,j;
    //freopen("in.txt","r",stdin);
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&n,&b);
        for(i=0; i<100; i++)
            ans[i]=0;
        for(i=0;; i++)
        {
            if(n==0)break;
            ans[i]+=n%b;
            n/=b;
        }
        for(j=i-1; j>=0; j--)
        {
                if(ans[j]<10)
                    printf("%d",ans[j]);
                else
                {
                    if(ans[j]==10)
                        printf("A");
                    if(ans[j]==11)
                        printf("B");
                    if(ans[j]==12)
                        printf("C");
                    if(ans[j]==13)
                        printf("D");
                    if(ans[j]==14)
                        printf("E");
                    if(ans[j]==15)
                        printf("F");
                }
        }
        printf("\n");
    }
    return 0;
}
