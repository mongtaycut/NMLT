//Bài 31: Cho số nguyên dương n. Kiểm tra xem n có phải là số nguyên tố hay không

#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    bool lasoNguyento = true;
    if (n <= 1)
    {
        lasoNguyento = false;
    }
    else
    {
        for (int i = 2 ; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                lasoNguyento = false;
                break;
            }
        }
    }
    if  (lasoNguyento)
        printf("%d la so nguyen to", n);
    else
        printf("%d KHONG la so nguyen to", n);
}