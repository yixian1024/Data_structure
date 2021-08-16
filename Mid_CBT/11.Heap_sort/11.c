#include<stdio.h>

int count;

void hanoi(int n,char buffer,char src,char dst)
{
    if(n==1)
    {
        count++;
        printf("move disk from %c to %c\n",src,dst);
        return;
    }
    else
    {
        hanoi(n-1,dst,src,buffer);
        count++;
        printf("move disk from %c to %c\n",src,dst);
        hanoi(n-1,src,buffer,dst);
    }
}

main()
{
    int n;
    //freopen("11input.txt","r",stdin);
    scanf("%d",&n);
    count=0;
    hanoi(n,'B','A','C');
    printf("%d",count);
}
