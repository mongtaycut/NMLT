//Bài 31: Cho số nguyên dương n. Kiểm tra xem n có phải là số nguyên tố hay không

#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    int s = 0;
    if (n <= 0)
    {
        printf("vui lap nhap so n > 0");
    }
    else if (n >= 2)
        {
            for (int i = 2; i < n-1; i++)
            {
                if (n % i == 0)
                {
                    s++;
                }
            }
            if (s > 0)
                printf("n khong phai la so nguyen to");
            else
                printf("n la so nguyen to");
        }    
    else
        printf("n khong phai la so nguyen to");
        return 0;
}

