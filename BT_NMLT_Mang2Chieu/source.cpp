#include <stdio.h>
#include "mang.h"
#include "songuyento.h"

int main()
{
    int a[30][40];
    int n, m;
    NhapMaTran(a, n, m);
    XuatMaTran(a, n, m);
    int kq = TongGiaTriNamTrenBien(a, n, m);
    printf("Ket qua la %d", kq);
    return 0;
} 