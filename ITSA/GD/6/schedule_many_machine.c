#include<stdio.h>

main()
{
    int n,m,i,j,max,min,mindex,job[100000],machine[10000];
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
        scanf("%d",job+i);
    for(i=0; i<m; i++)
        machine[i]=0;
    mindex=max=0;
    for(j=0; j<n; j++)
    {
        min=999999;
        machine[mindex]+=job[j];
        for(i=0; i<m; i++)
            if(machine[i]<min)
            {
                mindex=i;
                min=machine[i];
            }
    }
    for(i=0; i<m; i++)
        if(machine[i]>max)max=machine[i];
    printf("%d\n",max);

}
