#include<stdio.h>

main()
{
    int mark[10000],index,max,temp,i,flag,count;
    for(i=0;i<10000;i++)
        mark[i]=0;
    max=-1;
    flag=count=0;
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&temp)!=EOF)
    {
        mark[temp]++;
        if(mark[temp]>max)
        {
            max=mark[temp];
            index=temp;
            flag=1;
        }
        else if(mark[temp]==max)
            flag=0;
        count++;
    }
    if(max>count/2&&flag==1)
        printf("Majority is %d\n",index);
    else
        printf("No Majority\n");
}
