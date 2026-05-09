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

int KiemTraAConCuaB(int a[30][40], int n, int m, int b[30][40], int o, int p)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return false;
                break;
            }
        }
    }
    return true;
}


int main()
{
    int a[30][40], b[30][40];
    int n, m, o, p;
    NhapMaTran(a, n, m);
    NhapMaTran(b, o, p);
    XuatMaTran(a, n, m);
    XuatMaTran(b, o, p);
    int kq = KiemTraAConCuaB(a, n, m, b, o, p);
    printf("Ket qua la %d", kq);
    return 0;
}