#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    int s = 0;
    int i = 0;
    while (i <=n)
    {
        s = s + i;
        i = i + 1;
    }

    printf("Ket qua la %d", s);
    return 0;
}