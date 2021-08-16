#include<stdio.h>

typedef struct
{
    int col,row,value;
} matrix;

matrix a[1000],b[1000],trans[1000],ans[1000];

void transpose(void)
{
    int i,j;
    int rowterm[1000],startpositioin[1000];
    trans[0].row=b[0].col;
    trans[0].col=b[0].row;
    trans[0].value=b[0].value;
    for(i=0; i<=b[0].value; i++)
        rowterm[i]=0;
    for(i=1;i<=trans[0].value;i++)
        rowterm[b[i].col]++;
    startpositioin[0]=1;
    for(i=1;i<=b[0].col;i++)
        startpositioin[i]=startpositioin[i-1]+rowterm[i-1];
    printf("Starting position for each column of B:\n");
    for(i=0;i<b[0].col-1;i++)
        printf("%d ",startpositioin[i]-1);
    printf("%d",startpositioin[b[0].col-1]-1);
    printf("\n");
    for(i=1;i<=b[0].value;i++)
    {
        j=startpositioin[b[i].col]++;
        trans[j].col=b[i].row;
        trans[j].row=b[i].col;
        trans[j].value=b[i].value;
    }
    /*for(i=0; i<=trans[0].value; i++)
        printf("Trans:%d %d %d\n",trans[i].row,trans[i].col,trans[i].value);*/
    return;
}

void store_sum(int *count,int *sum,int row,int col)
{
    if(*sum)
    {
        ans[++*count].row=row;
        ans[*count].col=col;
        ans[*count].value=*sum;
        /*printf("row:%dcol:%dvalue:%d",row+1,col+1,*sum);
        printf("count%d\n",*count);*/
        *sum=0;
        ans[0].value=*count;
    }
    return;
}

int compare(int a,int b)
{
   if(a==b)return 0;
   if(a<b)return -1;
   if(a>b)return 1;
}

int mutiply(void)
{
    int i,j,k,count,row,col,sum,rowstart;
    ans[0].row=a[0].row;
    ans[0].col=trans[0].row;

    sum=count=0;
    i=rowstart=1;
    //set boundary
    a[a[0].value+1].row=a[0].row;
    trans[trans[0].value+1].row=trans[0].row;
    trans[trans[0].value+1].col=0;
    while(i<=a[0].value)
    {
        j=1;
        col=trans[j].row;
        while(j<=b[0].value+1)
        {
            if(a[i].row!=row)
            {
                store_sum(&count,&sum,row,col);
                i=rowstart;
                while(trans[j].row==col)
                    j++;
                col=trans[j].row;
            }
            else if(trans[j].row!=col)
            {
                store_sum(&count,&sum,row,col);
                i=rowstart;
                col=trans[j].row;
            }
            else
                switch(compare(a[i].col,trans[j].col))
                {
                    case -1:
                        i++;
                        break;
                    case 0:
                        {
                            sum+=a[i++].value*trans[j++].value;
                            //printf("sum:%d\n",sum);
                        }
                        break;
                    case 1:
                        j++;
                }
        }
        while(a[i].row==row)
            i++;
        row=a[i].row;
        rowstart=i;
    }
    return;
}

main()
{
    int i,j,k,temp;
    //freopen("1input.txt","r",stdin);

    //matrix a
    scanf("%d%d",&a[0].row,&a[0].col);
    k=1;
    for(i=0; i<a[0].row; i++)
        for(j=0; j<a[0].col; j++)
        {
            scanf("%d",&temp);
            if(temp!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].value=temp;
                k++;
            }
        }
    a[0].value=k-1;

    //matrix b
    scanf("%d%d",&b[0].row,&b[0].col);
    k=1;
    for(i=0; i<b[0].row; i++)
        for(j=0; j<b[0].col; j++)
        {
            scanf("%d",&temp);
            if(temp!=0)
            {
                b[k].row=i;
                b[k].col=j;
                b[k].value=temp;
                k++;
            }
        }
    b[0].value=k-1;

    /*for(i=0; i<=a[0].value; i++)
        printf("A:%d %d %d\n",a[i].row,a[i].col,a[i].value);
    for(i=0; i<=b[0].value; i++)
        printf("B:%d %d %d\n",b[i].row,b[i].col,b[i].value);*/

    transpose();
    mutiply();

    //output
    printf("A * B:\n");
    for(i=0; i<=ans[0].value; i++)
    {
        if(i!=0)
            printf("\n");
        printf("%d %d %d",ans[i].row,ans[i].col,ans[i].value);
    }
    return 0;
}
