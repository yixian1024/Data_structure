#include<stdio.h>

main()
{
    int option,n,i,j,flag=0;
    //freopen("in.txt","r",stdin);
    while(1)
    {
        scanf("%d%d",&option,&n);
        if(option==0&&n==0)
            return 0;
        switch(option)
        {
        case 1:
        {
            if(flag!=0)printf("\n");
            for(i=1; i<n; i++)
            {
                for(j=0; j<i; j++)
                    printf("*");
                printf("\n");
            }
            for(i=n; i>0; i--)
            {
                for(j=0; j<i; j++)
                    printf("*");
                printf("\n");
            }
            flag++;
        }
        continue;
        case 2:
        {
            if(flag!=0)printf("\n");
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                    printf("*");
                printf("\n");
            }
            flag++;
        }
        continue;

        }
    }
}

