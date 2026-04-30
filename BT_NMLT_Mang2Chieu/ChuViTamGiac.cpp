#include <stdio.h>
#include <math.h>

struct TamGiac {
    Diem A;
    Diem B;
    Diem C;
};

struct Diem {
    int X;
    int Y;
};

TamGiac NhapDiem() {
    TamGiac tg;
    printf("Nhap diem A: ");
    tg.A = NhapDiem();
    printf("Nhap diem B: ");
    tg.B = NhapDiem();
    printf("Nhap diem C: ");
    tg.C = NhapDiem();
    return tg;
}
    scanf("%d", &d.X);
    printf("Nhap tung do: ");
    scanf("%d", &d.Y);
    return d;
}

double TinhChuVi{
    return 
}