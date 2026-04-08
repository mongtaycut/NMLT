#include <stdio.h>
#include <math.h>
#include "mang.h"

int main() {
    //Khai bao mang so nguyen
    int arr[100];
    int n = 0; //n phai be hon 100
    int x, vt;
    //NhapMang(arr, n);

    void NhapMang(int arr[100], int &n, int x, int vt);
{
    printf("Nhap so luong phan tu mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n ; i++)
    {
        printf("Nhap phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    scanf("%d", &vt);
}
    //Tinh tong cac phan tu mang
    int kq = KiemTraMangTang(arr, n);
    //xuat mang
    XuatMang(arr, n);

    printf("\n Ket qua la %d", kq);

    return 0;
}