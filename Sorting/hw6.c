#include<stdio.h>
#include<stdlib.h>

typedef struct Player
{
    int point,card[10],id;
} Player;

typedef struct Table
{
    int id,mostcard,ncard,card[5];
} Table;

Table table[5];
Player player[10];
int front;

int playercardcmp(const void *a,const void *b)
{
    return (((Player*)a)->card[front]) - (((Player*)b)->card[front]);
}
int playeridcmp(const void *a,const void *b)
{
    return (((Player*)a)->id) - (((Player*)b)->id);
}
int tablemaxcardcmp(const void *a,const void *b)
{
    return (((Table*)b)->mostcard) - (((Table*)a)->mostcard);
}
int tablemincardcmp(const void *a,const void *b)
{
    return (((Table*)a)->mostcard) - (((Table*)b)->mostcard);
}
int tablencardcmp(const void *a,const void *b)
{
    return (((Table*)a)->ncard) - (((Table*)b)->ncard);
}
int tableidcmp(const void *a,const void *b)
{
    return (((Table*)a)->id) - (((Table*)b)->id);
}

main()
{
    int i,j,k,count,mark;
    FILE *input,*output;

    input=fopen("input6.txt","r");
    output=fopen("output6.txt","w");
    //read file
    for(i=0; i<4; i++)
    {
        fscanf(input,"%d",&table[i].mostcard);
        table[i].card[0]=table[i].mostcard;
        table[i].id=i;
        table[i].ncard=1;
    }
    for(i=0; i<10; i++)
    {
        player[i].id=i;
        for(j=0; j<9; j++)
            fscanf(input,"%d,",&player[i].card[j]);
        fscanf(input,"%d",&player[i].card[9]);
    }
    fclose(input);

    //initialize
    for(i=0; i<10; i++)
        player[i].point=66;
    for(i=0; i<4; i++)
        table[i].ncard=0;
    front=0;


    while(1)
    {
        if(front>10)
        {
            fclose(output);
            return 0;
        }
        qsort(table,4,sizeof(Table),tableidcmp);
        qsort(player,10,sizeof(Player),playeridcmp);
        //print
        printf("Round %d:\n",front);
        for(j=0; j<4; j++)
        {
            printf("In row %d:",table[j].id+1);
            for(k=0; k<=table[j].ncard; k++)
                printf("%d ",table[j].card[k]);
            printf("\n");
        }
        for(j=0; j<10; j++)
            printf("player:%d point:%d\n",player[j].id+1,player[j].point);
        printf("\n\n");

        //fprint
        fprintf(output,"Round %d:\n",front);
        for(j=0; j<4; j++)
        {
            fprintf(output,"In row %d:",table[j].id+1);
            for(k=0; k<=table[j].ncard; k++)
                fprintf(output,"%d ",table[j].card[k]);
            fprintf(output,"\n");
        }
        for(j=0; j<10; j++)
            fprintf(output,"player:%d point:%d\n",player[j].id+1,player[j].point);
        fprintf(output,"\n\n");

        qsort(player,10,sizeof(Player),playercardcmp);
        for(i=0; i<10; i++)
        {
            qsort(table,4,sizeof(Table),tablemaxcardcmp);
            mark=0;
            for(j=0; j<4; j++)
            {
                if(player[i].card[front]>table[j].mostcard)
                {
                    table[j].ncard++;
                    table[j].mostcard=player[i].card[front];
                    if(table[j].ncard==4)
                    {
                        player[i].point-=table[j].ncard;
                        table[j].ncard=0;
                    }
                    table[j].card[table[j].ncard]=player[i].card[front];
                    mark=1;
                    break;
                }
            }

            if(mark==0)
            {
                qsort(table,4,sizeof(Table),tablencardcmp);
                count=0;
                for(j=0; j<4; j++)
                    if(table[0].ncard==table[j].ncard)
                        count++;
                qsort(table,count,sizeof(Table),tablemincardcmp);
                player[i].point-=(table[0].ncard+1);
                table[0].ncard=0;
                table[0].mostcard=player[i].card[front];
                table[0].card[table[0].ncard]=player[i].card[front];
            }
        }
        front++;
    }
}
