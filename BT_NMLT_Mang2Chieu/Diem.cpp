#include <stdio.h>
#include <math.h>

//Nhap vao tam giac A, B, C. Tinh chu vi tam giac ABC
struct Diem {
    int X;
    int Y;
};
Diem NhapDiem() {
    Diem d;
    printf("Nhap hoanh do: ");
    scanf("%d", &d.X);
    printf("Nhap tung do: ");
    scanf("%d", &d.Y);
    return d;
}
struct TamGiac {
    Diem A;
    Diem B;
    Diem C;
};

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

double TinhKhoangCach(Diem A, Diem B) {
    return sqrt(pow(B.X - A.X, 2) + pow(B.Y - A.Y, 2));
}

double TinhChuVi(TamGiac tg) {
    double AB = TinhKhoangCach(tg.A, tg.B);
    double AC = TinhKhoangCach(tg.A, tg.C);
    double BC = TinhKhoangCach(tg.B, tg.C);
    return AB + AC + BC;
}

int main()
{
    TamGiac tg = NhapTamGiac();
    double chuVi = TinhChuVi(tg);
    printf("Chu vi tam giac ABC la: %.2f\n", chuVi);
    return 0;
}