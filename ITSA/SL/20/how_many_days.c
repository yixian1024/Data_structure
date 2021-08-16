#include<stdio.h>
main()
{
    int y,m,d,k,i,j,ncase;
    //freopen("in.txt","r",stdin);
    k=0;
    scanf("%d %d %d",&y,&m,&d);
    //default
    if(y<1970||m<1||m>12||d<1||d>31)
    {
        printf("invalid\n");
        return 0;
    }
    else if((m==4||m==6||m==9||m==11)&&d>30)
    {
        printf("invalid\n");
        return 0;
    }
    else if(m==2&&(i%400==0||(i%4==0&&i%100!=0))&&d>29)
    {
        printf("invalid\n");
        return 0;
    }
    else if(m==2&&!(i%400==0||(i%4==0&&i%100!=0))&&d>28)
    {
        printf("invalid\n");
        return 0;
    }
    //year
    for(i=1970; i<y; i++)
    {
        if(((i%400==0)&&(i%100!=0))||i%4==0)
            k+=366;
        else
            k+=365;
    }
    //month
    for(i=1; i<m; i++)
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            k+=31;
        else if(i==4||i==6||i==9||i==11)
            k+=30;
        else if(i==2&&((y%400==0)||((y%100!=0)&&(y%4==0))))
            k+=29;
        else
            k+=28;

    }
    //day
    k+=d;
    printf("%d\n",k);

    return 0;
}

