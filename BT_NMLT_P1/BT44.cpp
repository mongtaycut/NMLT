//Bài 44: Hãy tính tổng các chữ số của số nguyên dương n
//N = 15894
//S = 1 + 5 + 8 + 9

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);
    int s = 0;
    int donvi = 0;
    for (int i = 10 ; n*10 / i >= 1 ; n/=10 )
    {
        donvi = n % i;
        s = s + donvi;
        printf("%5d", s);
    }
    printf("tong cac chu so cua %d la %d ", n, s);
    return 0;
}