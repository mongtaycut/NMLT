#include "../include/tamgiac.h"
#include <math.h>
#include <stdio.h>
TamGiac NhapTamGiac() {
    TamGiac tg;
    printf("Nhap diem A: \n");
    tg.A = NhapDiem();
    printf("Nhap diem B: \n");
    tg.B = NhapDiem();
    printf("Nhap diem C: \n");
    tg.C = NhapDiem();
    return tg;
}

double TinhChuVi(TamGiac tg) {
    double AB = TinhKhoangCach(tg.A, tg.B);
    double AC = TinhKhoangCach(tg.A, tg.C);
    double BC = TinhKhoangCach(tg.B, tg.C);
    return AB + AC + BC;
}