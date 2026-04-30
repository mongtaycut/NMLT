#include "../include/Diem.h"

Diem NhapDiem() {
    Diem d;
    printf("Nhap hoanh do: ");
    scanf("%d", &d.x);
    printf("Nhap tung do: ");
    scanf("%d", &d.y);
    return d;
}

double TinhKhoangCach(Diem d1, Diem d2) {
    double dx = d2.x - d1.x;
    double dy = d2.y - d1.y;
    return sqrt(dx * dx + dy * dy);
}