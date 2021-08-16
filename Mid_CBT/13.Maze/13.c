#include<stdio.h>
#include<ctype.h>

typedef struct
{
    int x,y;
} Stack;

Stack stack[100],position;
int top,i,j,mark;

void push(void)
{
    top++;
    stack[top].x=j;
    stack[top].y=i;
    return;
}

void pop(void)
{
    top--;
    j=stack[top].x;
    i=stack[top].y;
    return;
}

main()
{
    int flag[10][10];
    char maze[20][20];
    //freopen("13input.txt","r",stdin);
    for(i=0; i<10; i++)
        for(j=0; j<10; j++)
        {
            scanf("%c",&maze[i][j]);
            flag[i][j]=0;
            if(!isdigit(maze[i][j]))
                j--;
        }
    /*for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
            printf("%c",maze[i][j]);
        printf("\n");
    }*/
    top=-1;
    i=j=1;
    push();
    flag[i][j]=1;
    while(1)
    {
        position.x=j;
        position.y=i;
        if(i==8&&j==8)
        {
            printf("(%d,%d)",position.x,position.y);
            return 0;
        }
        printf("(%d,%d),",position.x,position.y);
        if(maze[i][j+1]=='0'&&flag[i][j+1]!=1)
        {
            j++;
            flag[i][j]=1;
        }
        else if(maze[i+1][j]=='0'&&flag[i+1][j]!=1)
        {
            i++;
            flag[i][j]=1;
        }
        else if(maze[i][j-1]=='0'&&flag[i][j-1]!=1)
        {
            j--;
            flag[i][j]=1;
        }
        else if(maze[i-1][j]=='0'&&flag[i-1][j]!=1)
        {
            i--;
            flag[i][j]=1;
        }
        else
        {
            pop();
            continue;
        }
        push();
    }
}
