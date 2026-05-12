#include <stdio.h>
#include <stdbool.h>
#include "menu.h"

int main()
{
	// Khai bao mang luu thong tin khach hang
	int kh_id[100];
	char kh_hoTen[100][50];
	char kh_sdt[100][11];
	char kh_email[100][50];
	char kh_diaChi[100][100];
	int kh_ngayDk[100], kh_thangDk[100], kh_namDk[100];
	bool kh_isVIP[100];
    bool kh_isDeleted[100] = { false }; // Danh dau khach hang da bi xoa hay chua
    int kh_count = 0;

	//Khai bao mang luu thong tin sach
    char s_ISBN[100][14];
	char s_tenSach[100][100];
	char s_tacGia[100][50];
	char s_nxb[100][50];
	int s_namxb[100];
	char s_theLoai[100][30];
	int s_giaNhap[100];
	int s_giaBan[100];
	int s_tonKho[100];    
    int s_soLuong = 0;


	//Khai bao mang luu thong tin hoa don


    //Khai bao mang luu thong tin kho
	//Khai bao mang luu thong tin thong ke

	//Mo menu
    int ChonMenu;
    do {
        printf("\n=========================================\n");
        printf("       PHAN MEM QUAN LY NHA SACH       \n");
        printf("=========================================\n");
        printf("1. Quan ly khach hang\n");
        printf("2. Quan ly sach\n");
        printf("3. Lap hoa don ban hang\n");
        printf("4. Quan ly kho\n");
        printf("5. Thong ke\n");
        printf("6. Thoat phan mem\n");
        printf("-----------------------------------------\n");
        printf("Chon hang muc (1-6): ");
        scanf_s("%d", &ChonMenu);

        switch (ChonMenu) {
        case 1:
            Menu_QLKH(kh_id, kh_hoTen, kh_sdt, kh_email, kh_diaChi, kh_ngayDk, kh_thangDk, kh_namDk, kh_isVIP, kh_isDeleted, &kh_count);
            break;
        case 2:
			Menu_QLS(s_ISBN, s_tenSach, s_tacGia, s_nxb, s_namxb, s_theLoai, s_giaNhap, s_giaBan, s_tonKho, &s_soLuong);
            break;
        case 6:
            printf("Hen gap lai\n");
            break;
        }
    } while (ChonMenu != 6);
	return 0;
}