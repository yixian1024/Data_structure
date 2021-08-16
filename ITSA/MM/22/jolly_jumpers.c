#include<stdio.h>
int main(void)
{
    int ncase,num[3005],n,i,k,jolly;
    while(1)
    {
        jolly=1;
        if(scanf("%d",&n)==EOF)
            break;
        int flag[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            flag[i]=0;
        }
        for(i=0;i<n-1;i++)
        {
            k=num[i]-num[i+1];
            if(k<0)k=-k;
            if(k>n-1||k==0||flag[k]>0)jolly=0;
            if(jolly==0)break;
            flag[k]++;
        }
        if(jolly==1)printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
