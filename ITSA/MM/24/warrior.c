#include<stdio.h>

int main()
{
    int minearmy,opponent,difference;
    while(scanf("%d%d",&minearmy,&opponent)!=EOF)
    {
        difference=opponent-minearmy;
        printf("%d\n",abs(difference));
    }
    return 0;
}
