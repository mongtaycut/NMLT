//Bài 4: Tính S(n) = ½ + ¼ + … + 1/2n

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    float s = 0;
    int i = 1;
    while (i <= n)
    {
        s = s + 1/((float)i*2);
        i = i + 1;

    }
    printf("S(n)= %0.2lf", s);
    return 0;
}