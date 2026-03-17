#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Nhap a:");
    scanf("%d", &a);
    printf("Nhap b:");
    scanf("%d", &b);
    printf("Nhap c:");
    scanf("%d", &c);

    int delta = (b*b) - 4*a*c;
    if (delta < 0)
    {
        printf("Phuong trinh vo nghiem");
    }
    else if (delta == 0)
    { 
        double x1 = -1.0 * b / (2*a);
        printf("Phuong trinh co nghiem kep x = %0.2lf\n", x1);
    }
    else
    {
        double x1 = ( -1.0 * b + sqrt(b*b - 4*a*c) ) / (2*a);
        double x2 = ( -1.0 * b -sqrt (b*b - 4*a*c)) / (2*a); 
        printf("Phuong trinh co hai nghiem x1 = %0.2lf\n, x2 = %0.2lf\n", x1,x2);
    }
    return 0;
}