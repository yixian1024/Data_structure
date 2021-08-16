#include <stdio.h>
int main()
{
    int n,i,j,count,flag;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        count=0;
        flag=1;
        for(j=2; j<=n; j++)
        {
            for(i=2; i<=j/2; ++i)
            {
                // condition for nonprime number
                if(j%i==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                count++;
                //printf("prime:%d\n",j);
            }
            flag=1;
        }
        printf("%d\n",count);
    }
    return 0;
}
