#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "qlkh.h"
#include "qls.h"
#include "qlkho.h"
#include "thongke.h"

// Ham chon tinh nang co trong menu quan ly khach hang
void Menu_QLKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count) {
    int fnpick;
    do {
        printf("\n     QUAN LY KHACH HANG     \n");
        printf("----------------------------------\n");
        printf("1. Xem danh sach khach hang\n");
        printf("2. Them khach hang moi\n");
        printf("3. Chinh sua thong tin khach hang\n");
        printf("4. Xoa thong tin khach hang\n");
        printf("5. Tim khach hang theo so dien thoai\n");
        printf("6. Tim kiem khach hang theo ho ten\n");
        printf("7. Quay lai menu chinh\n");
        printf("Lua chon cua ban (1-7): ");
        scanf_s("%d", &fnpick);

        switch (fnpick) {
        case 1:
            XemDanhSachKH(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);
            break;
        case 2:
            ThemKH(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);
            break;
        case 3:
            SuaThongTinKH(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);
			break;
        case 4:
            XoaThongTinKH(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);
			break;
        case 5:
			TimKHTheoSDT(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);
        case 6:
			TimKHTheoTen(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);
        case 7:
            break;
        default:
            printf("\n>> Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (fnpick != 7);
}

//Ham chon tinh nang co trong menu quan ly sach
void Menu_QLS(char s_ISBN[][14], char s_tenSach[][100], char s_tacGia[][50], char s_nxb[][50], int s_namxb[], char s_theLoai[][30], int s_giaNhap[], int s_giaBan[], int s_tonKho[], int* s_soLuong) {
    int fnpick;
    do {
        printf("\n     QUAN LY SACH     \n");
        printf("----------------------------------\n");
        printf("1. Xem danh sach sach\n");
        printf("2. Them sach moi\n");
        printf("3. Chinh sua thong tin sach\n");
        printf("4. Xoa thong tin sach\n");
        printf("5. Tim kiem sach theo ISBN\n");
        printf("6. Tim kiem sach theo ten\n");
        printf("7. Quay lai menu chinh\n");
        printf("Lua chon cua ban (1-7): ");
        scanf_s("%d", &fnpick);
        switch (fnpick) {
        case 1:
            XemDanhSachS(s_ISBN, s_tenSach, s_tacGia, s_nxb, s_namxb, s_theLoai, s_giaNhap, s_giaBan, s_tonKho, s_soLuong);
            break;
        case 2:
			ThemS(s_ISBN, s_tenSach, s_tacGia, s_nxb, s_namxb, s_theLoai, s_giaNhap, s_giaBan, s_tonKho, s_soLuong);
            break;
        case 3:
            //SuaThongTinS(s_ISBN, s_tenSach, s_tacGia, s_nxb, s_namxb, s_theLoai, s_giaNhap, s_giaBan, s_tonKho, s_soLuong);
            break;
        case 4:
            //XoaThongTinS(s_ISBN, s_tenSach, s_tacGia, s_nxb, s_namxb, s_theLoai, s_giaNhap, s_giaBan, s_tonKho, s_soLuong);
            break;
        case 5:
            break;
        }
    } while (fnpick != 7);
}