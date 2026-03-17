//Bài 59: Hãy kiểm tra số nguyên dương n có phải là số đối xứng hay không
//N =12321
//12345
//54321
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    printf("Nhap n:");
    scanf("%d", &n);

    int len = sizeof(n);
    
    printf("%d", len);
}