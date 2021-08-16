#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int start,end;
} Time;

int compare(Time *a,Time *b)
{
    return a->start - b->start;
}

main()
{
    int i,ncase,n,temp,count,babysitter,length;
    Time time[55];
    //freopen("in.txt","r",stdin);
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        count=0;
        while(n--)
        {
            scanf("%d%d",&time[count].start,&time[count].end);
            if(time[count].start>time[count].end)
            {
                temp=time[count].start;
                time[count].start=time[count].end;
                time[count].end=temp;
            }
            count++;
        }
        qsort(time,count,sizeof(Time),compare);
        //printf("count %d\n",count);
        /*for(i=0;i<count;i++)
            printf("%d %d\n",(time[i].start),(time[i].end));*/
        babysitter=length=temp=i=0;
        while(length<200)
        {
            while(time[i].start<=length)
            {
                if(time[i].end>=temp)
                    temp=time[i].end+1;
                i++;
            }
            babysitter++;
            length=temp;
            //printf("%d\n",length);
        }
        printf("%d\n",babysitter);
    }
}
