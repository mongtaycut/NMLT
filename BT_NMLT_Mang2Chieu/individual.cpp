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

int SoPhanTuCucDai(int a[30][40], int n, int m)
{   
    bool isCucDai = true;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            isCucDai = true;
            for (int k = i-1 ; k <= i+1; k++)
            {
                for (int h = j-1; h <= j+1; h++)
                {
                    if (k >= 0 && k < n && h >= 0 && h < m && !(k == i && h == j))
                    {
                        if (a[k][h] > a[i][j])
                        {
                            isCucDai = false;
                        }
                    }
                }
            }
            if (isCucDai == true) {
                count++;
            }
        }
    }
    
    return count;
}

int main()
{
    int a[30][40];
    int n, m;
    NhapMaTran(a, n, m);
    XuatMaTran(a, n, m);
    int kq = SoPhanTuCucDai(a, n, m);
    printf("Ket qua la %d", kq);
    return 0;
}