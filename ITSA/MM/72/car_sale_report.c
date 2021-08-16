#include<stdio.h>

main()
{
    int id,nsale,i,j;
    float value;
    scanf("%d%d%f",&id,&nsale,&value);
    printf("%d %d %.2f %.2f %.2f\n",id,nsale,value,value*nsale,value*nsale*0.12);
}
