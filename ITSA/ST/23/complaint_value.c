#include<stdio.h>
int main()
{
    int n,complaint,a[100000],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    complaint=0;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
    {
        if(a[j]>a[i])
        {
            complaint++;
            //printf("com%d\n",complaint);
            //printf("a[%d]%d\n",i,a[i]);
        }
    }
    printf("Complaint =%d\n",complaint);
    return 0;
}
