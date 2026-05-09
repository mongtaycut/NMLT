#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "qlkh.h"

int main(void)
{
    int idKH[MAX_KH];
    char hoten[MAX_KH][MAX_HOTEN];
    char sdt[MAX_KH][MAX_SDT];
    char email[MAX_KH][MAX_EMAIL];
    char diachi[MAX_KH][MAX_DIACHI];
    int ngaydk[MAX_KH];
    int thangdk[MAX_KH];
    int namdk[MAX_KH];
    bool isVIP[MAX_KH];
    int soLuongKH = 0;
    int nextID = 1;

    memset(idKH, 0, sizeof(idKH));
    for (int i = 0; i < MAX_KH; i++)
    {
        hoten[i][0] = '\0';
        sdt[i][0] = '\0';
        email[i][0] = '\0';
        diachi[i][0] = '\0';
        ngaydk[i] = thangdk[i] = namdk[i] = 0;
        isVIP[i] = false;
    }

    HienThiMenu(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, &soLuongKH, &nextID);
    return 0;
}
