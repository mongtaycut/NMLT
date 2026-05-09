#include <stdio.h>
#include <math.h>
struct Diem {
    int x;
    int y;
};
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
struct DaGiac {
    Diem DanhSachDiem[100];
    int SoLuongDinh;
};
DaGiac NhapDaGiac() {
    DaGiac dg;
    printf("Nhap so luong dinh: ");
    scanf("%d", &dg.SoLuongDinh);
    for (int i = 0; i < dg.SoLuongDinh; i++) {
        printf("Nhap diem thu %d:\n", i + 1);
        dg.DanhSachDiem[i] = NhapDiem();
    }
    return dg;
}
double TinhChuVi(DaGiac dg) {
    double chuVi = 0.0;
    for (int i = 0; i < dg.SoLuongDinh; i++) {
        Diem d1 = dg.DanhSachDiem[i];
        Diem d2 = dg.DanhSachDiem[(i + 1) % dg.SoLuongDinh];
        chuVi += TinhKhoangCach(d1, d2);
    }
    return chuVi;

}
int main()
{    DaGiac dg = NhapDaGiac();
    double kq = TinhChuVi(dg);
    printf("Ket qua la: %.2f\n", kq);
    return 0;
}