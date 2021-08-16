#include<stdio.h>
#include<string.h>
main()
{

    char temp[30];
    int n,i,count,ans,cost,flag,price[1000];

    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    count=ans=0;
    while(n--)
    {
        scanf("%s%d",temp,&cost);
        flag=0;
        for(i=0;i<count;i++)
            if(price[i]==cost)
                flag=1;
        if(!flag)
        {
            price[count]=cost;
            ans++;
            count++;
        }
    }
    printf("%d\n",ans);
}
