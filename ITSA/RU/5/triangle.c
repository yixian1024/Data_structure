#include<stdio.h>
#include<stdlib.h>

int compare(int *a,int *b)
{
    return *a - *b;
}
main()
{
    int i,j,k,n,edge[1000],count;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",edge+i);
    qsort(edge,n,sizeof(int),compare);
    count=0;
    for(i=0; i<n-2; i++)
        for(j=i+1; j<n-1; j++)
            for(k=j+1; k<n; k++)
            {
                if(edge[k]<edge[i]+edge[j])
                    printf("%d %d %d\n",edge[i],edge[j],edge[k]);
                //printf("%d %d %d--%d\n",edge[i],edge[j],edge[k],count);
            }
}
