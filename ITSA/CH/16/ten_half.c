#include<stdio.h>
#include<ctype.h>
#include<string.h>

main()
{
    int ncase,i,j,len;
    float point,prob;
    char temp[200];

    //freopen("in.txt","r",stdin);
    scanf("%d\n",&ncase);
    while(ncase--)
    {
        scanf("\n");
        gets(temp);
        len=strlen(temp);
        point=0;
        for(i=0; i<len; i++)
        {
            if(isdigit(temp[i]))
                point+=(temp[i]-'0');
            else if(isalpha(temp[i]))
            {
                if(temp[i]=='A')
                    point+=1;
                else
                    point+=0.5;
            }
        }
        //printf("%.0f\n",point);
        if(point>10.5)
            prob=-1;
        else if((10.5-point)>=0.5)
            prob=100-(float)(((int)(10.5-point)+3))/13*100;
        else
            prob=100-(float)(((int)(10.5-point))/13*100);
        printf("%.0f\n",prob);
    }
}

