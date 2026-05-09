//Bài 336: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận các số thực
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void NhapMaTran(int a[30][40], int &n, int &m)
{
    printf("Nhap so dong: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);
    for (int i = 0; i < n ; i++)
    {
        for (int j=0; j <m ; j++)
        {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
           }
}

void XuatMaTran(int a[30][40], int n, int m)
{
    printf("\nCac phan tu trong mang la:\n");
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

int KiemTraCotGiamDan(int a[30][40], int n, int m, int k)
{
    for (int i = 0; i < n-1; i++)
    {
        if (a[i][k] < a[i+1][k])
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    int a[30][40];
    int n, m, k;
    NhapMaTran(a, n, m);
    XuatMaTran(a, n, m);
    printf("Nhap cot can kiem tra: ");
    scanf("%d", &k);
    int kq = KiemTraCotGiamDan(a, n, m, k);
    printf("Ket qua la %d", kq);
    return 0;
}