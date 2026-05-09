#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "qlkh.h"

static void NhapChuoi(const char prompt[], char dest[], int maxLen)
{
    char buffer[256];
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        dest[0] = '\0';
        return;
    }

    size_t len = strcspn(buffer, "\n");
    buffer[len] = '\0';
    strncpy(dest, buffer, maxLen);
    dest[maxLen - 1] = '\0';
}

static int NhapSoNguyen(const char prompt[], int minValue, int maxValue)
{
    char buffer[64];
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;
        if (sscanf(buffer, "%d", &value) == 1 && value >= minValue && value <= maxValue)
            return value;
        printf("Gia tri khong hop le. Vui long nhap lai.\n");
    }
}

static bool NhapYN(const char prompt[])
{
    char buffer[16];
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;
        if (buffer[0] == '\n')
            continue;
        char c = toupper((unsigned char)buffer[0]);
        if (c == 'Y')
            return true;
        if (c == 'N')
            return false;
        printf("Nhap Y hoac N. Vui long nhap lai.\n");
    }
}

static bool TenChuoiCon(const char haystack[], const char needle[])
{
    char haycopy[256];
    char needlecopy[256];
    strncpy(haycopy, haystack, sizeof(haycopy));
    strncpy(needlecopy, needle, sizeof(needlecopy));
    haycopy[sizeof(haycopy) - 1] = '\0';
    needlecopy[sizeof(needlecopy) - 1] = '\0';

    for (size_t i = 0; haycopy[i]; i++)
        haycopy[i] = (char)tolower((unsigned char)haycopy[i]);
    for (size_t i = 0; needlecopy[i]; i++)
        needlecopy[i] = (char)tolower((unsigned char)needlecopy[i]);

    return strstr(haycopy, needlecopy) != NULL;
}

static int TimIndexKhachHangTheoID(int idKH[MAX_KH], int soLuongKH, int searchID)
{
    for (int i = 0; i < soLuongKH; i++)
    {
        if (idKH[i] == searchID)
            return i;
    }
    return -1;
}

static int TimIndexKhachHangTheoSDT(int soLuongKH, char sdt[MAX_KH][MAX_SDT], const char searchSDT[])
{
    for (int i = 0; i < soLuongKH; i++)
    {
        if (strcmp(sdt[i], searchSDT) == 0)
            return i;
    }
    return -1;
}

void XemDanhSachKH(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH)
{
    if (soLuongKH == 0)
    {
        printf("\nHe thong hien tai chua co khach hang nao.\n");
        return;
    }

    printf("\nDanh sach khach hang:\n");
    for (int i = 0; i < soLuongKH; i++)
    {
        printf("ID: %d\n", idKH[i]);
        printf("Ho ten: %s\n", hoten[i]);
        printf("So dien thoai: %s\n", sdt[i]);
        printf("Email: %s\n", email[i]);
        printf("Dia chi: %s\n", diachi[i]);
        printf("Ngay dang ky: %02d/%02d/%04d\n", ngaydk[i], thangdk[i], namdk[i]);
        printf("Loai the: %s\n", isVIP[i] ? "VIP" : "Thuong");
        printf("-------------------------\n");
    }
}

bool ThemKhachHang(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int *soLuongKH, int *nextID)
{
    if (*soLuongKH >= MAX_KH)
    {
        printf("\nDa dat gioi han so luong khach hang. Khong the them them.\n");
        return false;
    }

    int index = *soLuongKH;
    idKH[index] = (*nextID)++;
    NhapChuoi("Nhap ho ten: ", hoten[index], MAX_HOTEN);
    NhapChuoi("Nhap so dien thoai: ", sdt[index], MAX_SDT);
    NhapChuoi("Nhap email: ", email[index], MAX_EMAIL);
    NhapChuoi("Nhap dia chi: ", diachi[index], MAX_DIACHI);
    ngaydk[index] = NhapSoNguyen("Nhap ngay dang ky (1-31): ", 1, 31);
    thangdk[index] = NhapSoNguyen("Nhap thang dang ky (1-12): ", 1, 12);
    namdk[index] = NhapSoNguyen("Nhap nam dang ky (1980-2099): ", 1980, 2099);
    isVIP[index] = NhapYN("Khach hang co phai VIP? (Y/N): ");

    (*soLuongKH)++;
    printf("\nDa them khach hang thanh cong voi ID = %d.\n", idKH[index]);
    return true;
}

bool SuaThongTinKH(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH)
{
    if (soLuongKH == 0)
    {
        printf("\nChua co khach hang de chinh sua.\n");
        return false;
    }

    int id = NhapSoNguyen("Nhap ID khach hang can chinh sua: ", 1, 1000000);
    int index = TimIndexKhachHangTheoID(idKH, soLuongKH, id);
    if (index < 0)
    {
        printf("Khong tim thay khach hang co ID = %d.\n", id);
        return false;
    }

    printf("\nThong tin hien tai:\n");
    printf("Ho ten: %s\n", hoten[index]);
    printf("So dien thoai: %s\n", sdt[index]);
    printf("Email: %s\n", email[index]);
    printf("Dia chi: %s\n", diachi[index]);
    printf("Ngay dang ky: %02d/%02d/%04d\n", ngaydk[index], thangdk[index], namdk[index]);
    printf("Loai the: %s\n", isVIP[index] ? "VIP" : "Thuong");

    NhapChuoi("Nhap ho ten moi: ", hoten[index], MAX_HOTEN);
    NhapChuoi("Nhap so dien thoai moi: ", sdt[index], MAX_SDT);
    NhapChuoi("Nhap email moi: ", email[index], MAX_EMAIL);
    NhapChuoi("Nhap dia chi moi: ", diachi[index], MAX_DIACHI);
    ngaydk[index] = NhapSoNguyen("Nhap ngay dang ky moi (1-31): ", 1, 31);
    thangdk[index] = NhapSoNguyen("Nhap thang dang ky moi (1-12): ", 1, 12);
    namdk[index] = NhapSoNguyen("Nhap nam dang ky moi (1980-2099): ", 1980, 2099);
    isVIP[index] = NhapYN("Khach hang co phai VIP? (Y/N): ");

    printf("\nDa cap nhat thong tin khach hang ID = %d.\n", idKH[index]);
    return true;
}

bool XoaThongTinKH(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int *soLuongKH)
{
    if (*soLuongKH == 0)
    {
        printf("\nChua co khach hang de xoa.\n");
        return false;
    }

    int id = NhapSoNguyen("Nhap ID khach hang can xoa: ", 1, 1000000);
    int index = TimIndexKhachHangTheoID(idKH, *soLuongKH, id);
    if (index < 0)
    {
        printf("Khong tim thay khach hang co ID = %d.\n", id);
        return false;
    }

    printf("\nBan co chac muon xoa khach hang %s (ID = %d)?\n", hoten[index], id);
    if (!NhapYN("Nhap Y de xoa, N de huy: "))
    {
        printf("Huy xoa thong tin.\n");
        return false;
    }

    for (int i = index; i < *soLuongKH - 1; i++)
    {
        idKH[i] = idKH[i + 1];
        strcpy(hoten[i], hoten[i + 1]);
        strcpy(sdt[i], sdt[i + 1]);
        strcpy(email[i], email[i + 1]);
        strcpy(diachi[i], diachi[i + 1]);
        ngaydk[i] = ngaydk[i + 1];
        thangdk[i] = thangdk[i + 1];
        namdk[i] = namdk[i + 1];
        isVIP[i] = isVIP[i + 1];
    }
    (*soLuongKH)--;
    printf("\nDa xoa khach hang ID = %d.\n", id);
    return true;
}

void TimKHTheoSDT(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH)
{
    if (soLuongKH == 0)
    {
        printf("\nChua co khach hang de tim.\n");
        return;
    }

    char searchSDT[MAX_SDT];
    NhapChuoi("Nhap so dien thoai can tim: ", searchSDT, MAX_SDT);
    int index = TimIndexKhachHangTheoSDT(soLuongKH, sdt, searchSDT);
    if (index < 0)
    {
        printf("Khong tim thay khach hang voi so dien thoai %s.\n", searchSDT);
        return;
    }

    printf("\nKet qua tim kiem:\n");
    printf("ID: %d\n", idKH[index]);
    printf("Ho ten: %s\n", hoten[index]);
    printf("So dien thoai: %s\n", sdt[index]);
    printf("Email: %s\n", email[index]);
    printf("Dia chi: %s\n", diachi[index]);
    printf("Ngay dang ky: %02d/%02d/%04d\n", ngaydk[index], thangdk[index], namdk[index]);
    printf("Loai the: %s\n", isVIP[index] ? "VIP" : "Thuong");
}

void TimKHTheoTen(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH)
{
    if (soLuongKH == 0)
    {
        printf("\nChua co khach hang de tim.\n");
        return;
    }

    char searchName[100];
    NhapChuoi("Nhap ho ten hoac chuoi ho ten can tim: ", searchName, sizeof(searchName));
    if (searchName[0] == '\0')
    {
        printf("Khong co ten de tim.\n");
        return;
    }

    bool found = false;
    printf("\nKet qua tim kiem theo ho ten:\n");
    for (int i = 0; i < soLuongKH; i++)
    {
        if (TenChuoiCon(hoten[i], searchName))
        {
            found = true;
            printf("ID: %d\n", idKH[i]);
            printf("Ho ten: %s\n", hoten[i]);
            printf("So dien thoai: %s\n", sdt[i]);
            printf("Email: %s\n", email[i]);
            printf("Dia chi: %s\n", diachi[i]);
            printf("Ngay dang ky: %02d/%02d/%04d\n", ngaydk[i], thangdk[i], namdk[i]);
            printf("Loai the: %s\n", isVIP[i] ? "VIP" : "Thuong");
            printf("-------------------------\n");
        }
    }
    if (!found)
        printf("Khong tim thay khach hang phu hop.\n");
}
