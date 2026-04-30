#include "qlkh.h"

//void NhapKH(int&idKH[500], char&hoten[500][50], char&sdt[500][15], char&email[500][5OTH], char&diachi[500][100], int&ngaydk[500], int&thangdk[500], int&namdk[500], bool&isVIP[500]);
void XemDanhSachKH(int idKH[500], char hoten[500][50], char sdt[500][15], char email[500][50], char diachi[500][100], int ngaydk[500], int thangdk[500], int namdk[500], bool isVIP[500])
{
    printf("Danh sach khach hang:\n");
    for (int i = 0; i < 500; i++)
    {
        if (idKH[i] != 0) // Assuming idKH[i] == 0 means the slot is empty
        {
            printf("ID: %d\n", idKH[i]);
            printf("Ho ten: %s\n", hoten[i]);
            printf("So dien thoai: %s\n", sdt[i]);
            printf("Email: %s\n", email[i]);
            printf("Dia chi: %s\n", diachi[i]);
            printf("Ngay dang ky: %02d/%02d/%04d\n", ngaydk[i], thangdk[i], namdk[i]);
            printf("VIP: %s\n", isVIP[i] ? "Co" : "Khong");
            printf("-------------------------\n");
        }
        else
        {
            printf("He thong khong co khach hang nao de hien thi. Tao khach hang moi?\n (Y/N): ");
            scanf(" %d", &fnpick);
            break; // Stop printing when we reach an empty slot
        }
    }
}