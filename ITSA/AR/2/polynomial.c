#include<stdio.h>
main()
{
    int ncase,a[10],b[50],temp[50],d,i,j,index;
    while(scanf("%d%d%d%d",a+2,a+1,a,&d)!=EOF)
    {
        for(i=0;i<50;i++)
            b[i]=1;
        for(i=0;i<3;i++)
            b[i]=a[i];
        index=2;
        d--;
        while(d--)
        {
            for(i=0;i<50;i++)
                temp[i]=0;
            for(i=0;i<3;i++)
                for(j=0;j<=index;j++)
                    temp[j+i]+=b[j]*a[i];
            index+=2;
            for(i=0;i<=index;i++)
                b[i]=temp[i];
        }
        for(i=index;i>=0;i--)
            if(i!=0)
                printf("%d ",b[i]);
        else
            printf("%d\n",b[i]);
    }
    return 0;
}
