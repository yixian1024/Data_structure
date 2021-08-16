#include <stdio.h>

int main()
{
    int a,b,c,temp;
    scanf("%d%d%d",&a,&b,&c);
    if(a>c)
    {
        temp=c;
        c=a;
        a=temp;
    }
    if(b>c)
    {
        temp=c;
        c=b;
        b=temp;
    }
    if(a+b<=c||a<=0||b<=0||c<=0)
        printf("invalid\n");
    else
    {
        if(a*a+b*b<c*c)
            printf("obtuse\n");
        else if(a*a+b*b==c*c)
            printf("right\n");
        else if(a*a+b*b>c*c)
            printf("acute\n");

    }

    return 0;
}
