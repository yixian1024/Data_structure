
#include<stdio.h>

int cmp(int *a,int *b)
{
    return *a - *b;
}
main()
{
    int n,m,i,j,job[3000],machine[10];
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
        scanf("%d",job+i);
    for(i=0; i<m; i++)
        machine[i]=0;
    for(j=0; j<n; j++)
    {
        machine[0]+=job[j];
        qsort(machine,m,sizeof(int),cmp);
    }
    printf("%d\n",machine[m-1]);
}
