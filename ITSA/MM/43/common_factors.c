#include<stdio.h>
main()
{
    int n,i,gcd;
    int arr[1000];
    //freopen("in.txt","r",stdin);
    for(i=0;;i++)
    {
        if(scanf("%d",&arr[i])==EOF)
            break;
        //printf("%d\n",arr[i]);
    }
    n=i;
    gcd=arr[0];
    int j=1;
    while(j<n)
    {
       if(arr[j]%gcd==0)
           j++;
       else
       {
           gcd=arr[j]%gcd;
           i++;
       }
    }
    printf("Common factor in ascending order:\n");
    for(i=2;i<gcd;i++)
        if(gcd%i==0)
        printf("%d ",i);
    printf("%d\n",gcd);
    return 0;
}
