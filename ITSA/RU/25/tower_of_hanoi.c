#include <stdio.h>
#include <stdlib.h>

int time = 0;

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        time++;
    }
    else
    {
        hanoi(n - 1, A, C, B);
        time++;
        hanoi(n - 1, B, A, C);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("%d\n",time);
}

