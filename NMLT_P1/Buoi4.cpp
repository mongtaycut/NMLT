#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    int s = 0;

    for (int i = 1; i <= n ; i++)
    {
        printf("%5d", i);
    }
    printf("ket qua la %d", s);
}