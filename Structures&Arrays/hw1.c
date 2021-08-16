#include<stdio.h>
#include<string.h>
#include<ctype.h>

//first and second number
typedef struct Num
{
    char first[100000];
    char second[100000];
}Num;

Num num[1000];
int index[1000];
int count_id=0;
FILE *file;
char file_name[20];

void read_number(int x)
{
    char temp[5];
    int id,i;
    char string[10000];
    char *token;
    char c[5]=",";

    printf("Please input the file name:");
    scanf("%s",file_name);
    file=fopen(file_name,"r");

    //if no such file
    if(file==NULL)
    {
        printf("Open file error\n\n");
        return;
    }

    else
        printf("reads successfully\n\n");
    //take front that not belong to the numbers
    fscanf(file,"%s",string);
    //read data
    while(fscanf(file,"%s",string)!=EOF)
    {
        token=strtok(string,c);
        while(token!=NULL)
        {
            sscanf(token,"%s",temp);
            id=0;
            for(i=0; i<strlen(temp); i++)
                id=id*10+temp[i]-'0';
            token=strtok(NULL,c);
            sscanf(token,"%s",num[id].first);
            token=strtok(NULL,c);
            sscanf(token,"%s",num[id].second);
            token=strtok(NULL,c);
            count_id++;
            //printf("id:%d num1:%s num2:%s\n",id,num[id].first,num[id].second);
        }
    }
    fclose(file);
    return;
}

void show_input(int x)
{
    int j,k,id,len1,len2;
    float a,b;
    fopen(file,"r");
    //if no such a file
    if(file==NULL)
    {
        printf("Must read csv file first!\n\n");
        return;
    }

    printf("Here is your record:\n\n");

    //save as integer
    for(j=1; j<=count_id; j++)
    {
        len1=strlen(num[j].first);
        len2=strlen(num[j].second);
        a=b=0;
        if(len1>=3)
            for(k=2; k>=0; k--)
                a=a/10+num[j].first[k]-'0';
        else
        {
            if(len1==1)
                a=num[j].first[0]-'0';
            else if(len1==2)
                a=num[j].first[0]-'0'+(float)(num[j].first[1]-'0')/10;
        }
        if(len2>=3)
            for(k=2; k>=0; k--)
                b=b/10+num[j].second[k]-'0';
        else
        {
            if(len2==1)
                b=num[j].second[0]-'0';
            else if(len2==2)
                b=num[j].second[0]-'0'+(float)(num[j].second[1]-'0')/10;
        }
        //printf("No.%d:%s , %s\n",j,num1[j],num2[j]);
        printf("No.%d:%.2fe+%.3d , ",j,a,len1-1);
        printf("No.%d:%.2fe+%.3d\n",j,b,len2-1);
    }
    fclose(file);
    printf("\n");
    return;
}

void write_number(int x)
{
    int id;
    fopen(file,"a");
    //if no such file
    if(file==NULL)
    {
        printf("Must open csv file first!\n\n");
        return;
    }
    count_id++;
    id=count_id;
    //scan input number
    printf("No.%d\n",id);
    printf("Number1:");
    scanf("%s",&num[id].first);
    printf("Number2:");
    scanf("%s",&num[id].second);
    //save in the file
    fprintf(file,"%d %s %s\n",count_id,num[id].first,num[id].second);
    fclose(file);
    return;
}

void calculate(int l)
{
    char mark;
    int id,flag,len1,len2,i,j,k,n,m;
    int a[10000],b[10000];
    while(1)
    {
        //choose operation
        printf("\n= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("\tWhich operators do you want to choose?\n");
        printf("\t(+)Addition\n");
        printf("\t(-)Subtraction\n");
        printf("\t(*)Multiplication\n");
        printf("\t(/)Division\n");
        printf("\t(q)Quit\n");
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf(">");

        while(1)
        {
            scanf("%c",&mark);
            if(mark=='+'||mark=='-'||mark=='*'||mark=='/'||mark=='q')
                break;
        }
        if(mark=='q')
            return;

        //choose to read new number or read from file
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("\tWhich items do you want to choose?\n");
        printf("\t(1)Load the existing numbers by ID\n");
        printf("\t(2)Input two numbers to calculate\n");
        printf("\t(0)Quit\n");
        printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf(">");

        scanf("%d",&flag);

        //if data from file
        if(flag==1)
        {
            fopen(file,"r");
            if(file==NULL)
            {
                printf("Must read csv file first!\n\n");
                return;
            }
            printf("\nWhat index do you want to read?\n");
            scanf("%d",&id);
            if(id>count_id)
            {
                printf("\tThe number didn't exist");
                continue;
            }
            printf("\tFirst number:%s\n",num[id].first);
            printf("\tSecond number:%s\n",num[id].second);
            len1=strlen(num[id].first);
            len2=strlen(num[id].second);
            //save as integer
            for(i=0; i<=len1; i++)
                a[i]=num[id].first[i]-'0';
            for(i=0; i<=len2; i++)
                b[i]=num[id].second[i]-'0';
        }

        //if input a new number
        else if(flag==2)
        {
            printf("First number:");
            scanf("%s",num[0].first);
            printf("Second number:");
            scanf("%s",num[0].second);
            len1=strlen(num[0].first);
            len2=strlen(num[0].second);
            for(i=0; i<=len1; i++)
                a[i]=num[0].first[i]-'0';
            for(i=0; i<=len2; i++)
                b[i]=num[0].second[i]-'0';
        }
        //quit
        else if(flag==0)
        {
            fclose(file);
            printf("\n");
            return;
        }
        //add
        if(mark=='+')
        {
            if(len1>len2)
            {
                k=0;
                for(i=len1-1,j=len2-1; j>=0; j--,i--)
                {
                    a[i]=a[i]+b[j];
                    if(a[i]>=10)
                    {
                        a[i-1]++;
                        a[i]%=10;
                        if(i==0)k=1;
                    }
                }
                printf("Ans:");
                if(k==1)printf("1");
                for(i=0; i<len1; i++)
                    printf("%d",a[i]);
            }
            else
            {
                k=0;
                for(i=len1-1,j=len2-1; i>=0; j--,i--)
                {
                    b[j]=a[i]+b[j];
                    if(b[j]>=10)
                    {
                        b[j-1]++;
                        b[j]%=10;
                        if(j==0)k=1;
                    }
                }
                printf("Ans:");
                if(k==1)printf("1");
                for(i=0; i<len2; i++)
                    printf("%d",b[i]);
            }
        }

        //subtract
        else if(mark=='-')
        {
            if(len1>len2)
            {
                for(i=len1-1,j=len2-1; j>=0; j--,i--)
                    a[i]=a[i]-b[j];
                for(i=len1-1; i>=0; i--)
                    if(a[i]<0)
                    {
                        a[i-1]--;
                        a[i]+=10;
                    }
                printf("Ans:");
                for(i=0; i<len1; i++)
                    printf("%d",a[i]);
            }
            else if(len1<len2)
            {
                for(i=len1-1,j=len2-1; i>=0; j--,i--)
                    b[j]=b[j]-a[i];
                for(j=len2-1; j>=0; j--)
                    if(b[j]<0)
                    {
                        b[j-1]--;
                        b[j]+=10;
                    }
                printf("Ans:-");
                for(i=0; i<len2; i++)
                    printf("%d",b[i]);

            }
            else
            {
                k=0;
                for(i=len1-1; i>=0; i--)
                    a[i]=a[i]-b[i];
                for(i=0; i<len1; i++)
                {
                    if(a[i]>0)
                    {
                        k=1;
                        break;
                    }
                    if(a[i]<0)
                    {
                        k=-1;
                        break;
                    }
                }
                if(k==1)
                {
                    for(i=len1-1; i>=0; i--)
                        if(a[i]<0)
                        {
                            a[i-1]--;
                            a[i]+=10;

                        }
                    printf("Ans:");
                    for(i=0; i<len1; i++)
                        if(a[i]!=0)
                        {
                            printf("%d",a[i]);
                            break;
                        }

                    for(i=i+1; i<len1; i++)
                        printf("%d",abs(a[i]));
                }
                else if(k==-1)
                {
                    for(i=len1-1; i>=0; i--)
                        if(a[i]>0)
                        {
                            a[i-1]++;
                            a[i]-=10;
                        }
                    printf("Ans:-");
                    for(i=0; i<len1; i++)
                        if(a[i]!=0)
                        {
                            printf("%d",abs(a[i]));
                            break;
                        }

                    for(i=i+1; i<len1; i++)
                        printf("%d",abs(a[i]));
                }
                else
                    printf("Ans:0\n");
            }
        }
        //multiply
        else if(mark=='*')
        {
            int ans[10000];
            for(i=0; i<10000; i++)
                ans[i]=0;
            //printf("len1%d\n",len1);
            for(i=len1-1; i>=0; i--)
                for(j=len2-1,k=len1-1-i; j>=0; j--,k++)
                {
                    ans[k]+=a[i]*b[j];
                    //printf("%d/",ans[k]);
                    n=k;
                    if(ans[k]>=10)
                    {
                        ans[k+1]+=ans[k]/10;
                        ans[k]%=10;
                        n=k+1;
                    }
                }
            printf("Ans:");
            for(i=n; i>=0; i--)
                printf("%d",ans[i]);
        }

        //divide
        else if(mark=='/')
        {
            printf("Count yourself.\n");
        }
        printf("\n");
    }
}


main()
{
    int option;
    while(1)
    {
        //choose what to do
        printf("\nWhat do you want to do?\n\n");
        printf("\t1)Read numbers from a file\n");
        printf("\t2)Show the input numbers\n");
        printf("\t3)Write numbers to a file\n");
        printf("\t4)Calculate the big numbers\n");
        printf("\t0)Exit\n\n>");

        scanf("%d",&option);

        switch(option)
        {
        case 1:
            read_number(option);
            break;
        case 2:
            show_input(option);
            break;
        case 3:
            write_number(option);
            break;
        case 4:
            calculate(option);
            break;
        case 0:
            printf("bye bye!\n");
            return 0;
        }
    }

}
