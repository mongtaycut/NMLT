//Bài 3: Tính S(n) = 1 + ½ + 1/3 + … + 1/n

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
    s = s + 1/(float)i;
    i = i + 1;
 }

 printf("Tong s(%d) = %0.5f",n, s);
 return 0;

}