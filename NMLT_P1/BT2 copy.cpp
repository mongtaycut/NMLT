// Tính S(n) = 1^2 + 2^2 + ... + n^2

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    
    int s = 0;
    int i = 1;

    while (i <= n)
    {
        s = s + i*i;
        i = i + 1;
    }

    printf("Tong S(%d) = %d", n, s);
    return 0;
}