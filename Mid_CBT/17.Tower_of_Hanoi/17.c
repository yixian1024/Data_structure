#include<stdio.h>

void hanoi(int n,char buffer,char src,char dst)
{
    if(n==1)
    {
        return;
    }
    else
    {
        hanoi(n-1,dst,src,buffer);
        hanoi(n-1,src,buffer,dst);
    }
}

main()
{
    int n,i,count=1;
    //freopen("17input.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        count=count*2;
    printf("%d",count-1);
    hanoi(n,'B','A','C');

}
