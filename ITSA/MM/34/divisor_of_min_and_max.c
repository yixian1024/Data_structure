#include<stdio.h>
#define MIN 99999
#define MAX -1

main()
{
    int ncase,n,num,min,max,i,temp;
    scanf("%d",&ncase);
    while(ncase--)
    {
     scanf("%d",&n);
     min=MIN;
     max=MAX;
     for(i=0;i<n;i++)
     {
         scanf("%d",&num);
         if(num<min)min=num;
         if(num>max)max=num;
     }
        while(1)
        {
            if(min==0)break;
            max=max%min;
            temp=max;
            max=min;
            min=temp;
        }
        printf("%d\n",max);
    }
}
