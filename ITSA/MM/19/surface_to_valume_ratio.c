#include<stdio.h>

int main(void)
{
    int ncase,valume,surface,a,b,c,minsurface,minvalume,temp,tmp1,tmp2;
    float compare,minratio;
    scanf("%d",&ncase);
    minratio=999999;
    while(ncase--)
    {
        scanf("%d%d%d",&a,&b,&c);
        valume=a*b*c;
        surface=a*b*2+a*c*2+b*c*2;
        compare=surface/valume;
        if(compare<minratio)
        {
            minsurface=surface;
            minvalume=valume;
            minratio=compare;
            //printf("surface%d valume%d\n",surface,valume);
        }
    }
    tmp1=minsurface;
    tmp2=minvalume;
    while(1)
    {
        if(tmp2==0)break;
        tmp1=tmp1%tmp2;
        temp=tmp1;
        tmp1=tmp2;
        tmp2=temp;
    }
    //printf("tmp1%d tmp2%d\n",tmp1,tmp2);
    minsurface/=tmp1;
    minvalume/=tmp1;
    printf("%d/%d\n",minsurface,minvalume);
    return 0;
}
