#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    int s = 1;
    for (int i = 2; i<= n / 2 ; i++)
    {
        if (n % i == 0)
            s = s + i;
    }
    if (n>1)
        s = s+n;

    printf("Tong s = %d", s);
    return 0;
}