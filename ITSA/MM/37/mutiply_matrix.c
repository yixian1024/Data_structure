#include <stdio.h>
int main()
{
    int m, n, p, q, c, d, k, sum = 0,ncase;
    int first[100][1000], second[100][1000], multiply[100][1000];
    //freopen("in.txt","r",stdin);
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d", &m, &n);
        for (c = 0; c < m; c++)
            for (d = 0; d < n; d++)
                scanf("%d", &first[c][d]);
        p=n;q=m;
        for (c = 0; c < p; c++)
            for (d = 0; d < q; d++)
                scanf("%d", &second[c][d]);

        for (c = 0; c < m; c++)
            for (d = 0; d < q; d++)
            {
                for (k = 0; k < p; k++)
                    sum = sum + first[c][k]*second[k][d];
                multiply[c][d] = sum;
                sum = 0;
            }
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < q-1; d++)
                printf("%d ", multiply[c][d]);
            printf("%d", multiply[c][q-1]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
