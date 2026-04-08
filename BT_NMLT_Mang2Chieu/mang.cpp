#include <stdio.h>
#include <math.h>
#include "mang.h"
#include "songuyento.h" // Nhớ đảm bảo bạn có file này và có hàm KiemTraNguyenTo nhé

void NhapMang(int arr[30][40], int &n, int &m)
{
    printf("Nhap so dong: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void XuatMang(int arr[30][40], int n, int m)
{
    printf("\nCac phan tu trong mang la:\n");
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

int TinhTong(int arr[30][40], int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            s = s + arr[i][j];
        }
    }
    return s;
}