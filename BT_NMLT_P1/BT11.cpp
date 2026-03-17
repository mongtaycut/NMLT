#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("nhap n:");
    scanf("%d", &n);

    int s = 0;
    int p = 1;
    int i = 1;
    while (i <= n)
    {
        p = p*i;
        s = s + p;
        i = i + 1;
    } 

    printf("tong s = %d",s);
    return 0;
}