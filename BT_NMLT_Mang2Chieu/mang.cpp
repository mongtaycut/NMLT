#include <stdio.h>
#include <math.h>
#include "mang.h"
#include "songuyento.h"

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

int TinhTong(int a[30][40], int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            s = s + a[i][j];
        }
    }
    return s;
}

int TinhTrungBinh(int a[30][40], int n, int m)
{
    int s = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (KiemTraNguyenTo(a[i][j]) == true)
            {
                s = s + a[i][j];
                count++;
            }
        }
    }
    if (count == 0) {
        return 0; // Tránh chia cho 0 nếu không có số nguyên tố nào
    }
    return s / count;
}

int TongGiaTriNamTrenBien(int a[30][40], int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + a[i][0] + a[i][m - 1];
    }
    for (int j = 0; j < m; j++)
    {
        s = s + a[0][j] + a[n - 1][j];
    }
    return s;
}