#include <stdio.h>
#include <math.h>
#include "../include/tamgiac.h"

int main()
{
    TamGiac tg = NhapTamGiac();
    double kq;
    kq = TinhChuVi(tg);
    printf("Ket qua la: %.2f\n", kq);
    return 0;
}