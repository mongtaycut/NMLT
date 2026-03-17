#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    int i = 1;
    while (i <= n)
    {
        printf("%5d",i);
        i = i + 1;
    }
    return 0;
}