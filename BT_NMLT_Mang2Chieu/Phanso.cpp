#include <stdio.h>
#include <math.h>

struct PhanSo {
    int tuSo;
    int mauSo;
};
PhanSo NhapPhanSo() {
    PhanSo ps;
    printf("Nhap tu so: ");
    scanf("%d", &ps.tuSo);
    printf("Nhap mau so: ");
    scanf("%d", &ps.mauSo);
    return ps;
}

PhanSo TinhTong2    PhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    kq.mauSo = ps1.mauSo * ps2.mauSo;
    return kq;
}

int main()
{
    #Nhap vao 2 diem A, B. Tinh khoang cach tu A den B
    
}