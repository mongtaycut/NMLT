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

//Tìm ma trận con có tổng lớn nhất
int MaTranConTongLonNhat(int a[30][40], int n, int m, int &xMax, int &yMax, int &dMax, int &cMax)
{
    int maxSum = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int sum = 0;
            for (int k = 1; k < n; k++)
            {
                for (int h = 1; h < m; h++)
                {
                    sum += a[i + k][j + h];
                }
            }
            if (sum > maxSum)
            {
                xMax = i ; yMax = j; dMax = k; cMax = h;
                maxSum = sum;
            }
        }
    }
    return 0;
}


int main()
{
    int a[30][40];
    int n, m;
    NhapMaTran(a, n, m);
    XuatMaTran(a, n, m);
    int xMax, yMax, dMax, cMax;
    MaTranConTongLonNhat(a, n, m, xMax, yMax, dMax, cMax);
    printf("Ket qua la (%d, %d, %d, %d)", xMax, yMax, dMax, cMax);
    return 0;
}