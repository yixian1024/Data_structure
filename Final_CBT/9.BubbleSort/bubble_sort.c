#include<stdio.h>

int main(void)
{
    int data[100000],n,i,j,k,temp;
    //freopen("in.txt","r",stdin);
    for(i=0; scanf("%d",data+i)!=EOF; i++)
        n=i+1;
    for (i=n-1; i>0; i--)
    {
        for (j=0; j<i; j++)
            if(data[j]>data[j+1])
            {
                temp= data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
            }
        for(k=0; k<n-1; k++)
            printf("%d ",data[k]);
        printf("%d\n",data[n-1]);
    }
    return 0;
}
