#include<stdio.h>

int main()
{
    int adult,child,senior,fare1,fare2,fare3,total;
    scanf("%d%d",&adult,&fare1);
    scanf("%d%d",&child,&fare2);
    scanf("%d%d",&senior,&fare3);
    total=adult*fare1+child*fare2+senior*fare3;
    printf("%d\n",total);
    return 0;
}
