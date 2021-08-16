#include<stdio.h>
typedef struct
{
    int time,deadline;
}Job;
int cmp(Job *a,Job *b)
{
    return a->deadline - b->deadline;
};

main()
{
    int i,j,ncase,n,sum,ans;
    Job a[100];
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i].time);
        for(i=0;i<n;i++)
            scanf("%d",&a[i].deadline);
        qsort(a,n,sizeof(Job),cmp);
        sum=0;
        //for(i=0;i<n;i++)
          //  printf("%d %d\n",a[i].deadline,a[i].time);
        ans=1;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i].time;
            if(sum>a[i].deadline)
            {
                ans=0;
                break;
            }
            //printf("%d",ans);
        }
        if(ans==0)printf("No\n");
        else printf("Yes\n");
    }
}
