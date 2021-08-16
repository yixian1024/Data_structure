
#include<stdio.h>
#define N 10005

main()
{
    int ncase,n,m,i,j,temp,payment,flag,item[N],student[N];
    //freopen("in.txt","r",stdin);
    scanf("%d",&ncase);
    while(ncase--)
    {
        payment=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&item[i]);
        for(i=0;i<m;i++)
            scanf("%d",&student[i]);
        //bubble sort
        for(i=0;i<n;i++)
            for(j=0;j<n-i;j++)
            {
                if(item[j]<item[j-1])
                {
                    temp=item[j];
                    item[j]=item[j-1];
                    item[j-1]=temp;
                }
            }
        for(i=0;i<m;i++)
            for(j=0;j<m-i;j++)
            {
                if(student[j]<student[j-1])
                {
                    temp=student[j];
                    student[j]=student[j-1];
                    student[j-1]=temp;
                }
            }
        //devide job
        i=j=0;
        while(1)
        {
            if(i==n)
            {
                flag=1;
                break;
            }
            if(j==m&&i!=n)
            {
                flag=-1;
                break;
            }
            if(item[i]<=student[j])
            {
                payment+=student[j];
                i++;
                j++;
            }
            else j++;
        }
        if(flag==-1)printf("-1\n");
        else printf("%d\n",payment);
    }
}
