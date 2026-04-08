#include <stdio.h>
#include <math.h>
#include "mang.h"

int main() {
    //Khai bao mang so nguyen
    int arr[30][40];
    int n = 0; //n phai be hon 100
    int m = 0; //m phai be hon 100
    NhapMang(arr, n, m);
    //Tinh tong cac phan tu mang
    int kq = TinhTong(arr, n, m);
    //xuat mang
    XuatMang(arr, n, m);

    printf("\n Ket qua la %d", kq);

    return 0;
}