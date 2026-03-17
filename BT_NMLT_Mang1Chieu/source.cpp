#include <stdio.h>
#include <math.h>
#include "mang.h"

int main() {
    //Khai bao mang so nguyen
    int arr[100];
    int n = 0; //n phai be hon 100
    NhapMang(arr, n);

    //Tinh tong cac phan tu mang
    int kq = PhanTuAmLonNhat(arr, n);
    //xuat mang
    XuatMang(arr, n);

    printf("\n Ket qua la %d", kq);

    return 0;
}