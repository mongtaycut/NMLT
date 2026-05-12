#include <stdio.h>
#include "qls.h"

//Ham xem cac sach dang co trong he thong
void XemDanhSachS(char s_ISBN[][14], char s_tenSach[][100], char s_tacGia[][50], char s_nxb[][50], int s_namxb[], char s_theLoai[][30], int s_giaNhap[], int s_giaBan[], int s_tonKho[], int* s_soLuong)
{
	printf("\n--- DANH SACH SACH ---\n");
	if (*s_soLuong == 0) {
		printf("He thong chua co sach nao!\n");
		return;
	}
	printf("%-5s | %-15s | %-25s | %-20s | %-15s | %-10s | %-10s | %-10s | %-10s\n",
		"STT", "ISBN", "Ten Sach", "Tac Gia", "Nha Xuat Ban", "Nam XB", "The Loai", "Gia Nhap", "Gia Ban");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < *s_soLuong; i++)
	{
		printf("%-5d | %-15.15s | %-25.25s | %-20.20s | %-15.15s | %4d | %-10.10s | %10d | %10d\n",
			i + 1,
			s_ISBN[i],
			s_tenSach[i],
			s_tacGia[i],
			s_nxb[i],
			s_namxb[i],
			s_theLoai[i],
			s_giaNhap[i],
			s_giaBan[i]);
	}
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

// Ham them sach moi vao he thong, tu dong tang so luong sach sau khi them moi
void ThemS(char s_ISBN[][14], char s_tenSach[][100], char s_tacGia[][50], char s_nxb[][50], int s_namxb[], char s_theLoai[][30], int s_giaNhap[], int s_giaBan[], int s_tonKho[], int* s_soLuong)
{
	printf("\n--- THEM SACH MOI ---\n");
	if (*s_soLuong >= 100)
	{
		printf("Danh sach sach da day. Vui long xoa bot truoc khi tiep tuc\n");
		return;
	}
	int viTri = *s_soLuong;
	while (getchar() != '\n'); //xoa bo dem
	printf("Vui long nhap ISBN: ");
	scanf_s("%[^\n]", s_ISBN[viTri], 14);
	printf("Vui long nhap Ten Sach: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", s_tenSach[viTri], 100);
	printf("Vui long nhap Tac Gia: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", s_tacGia[viTri], 50);
	printf("Vui long nhap Nha Xuat Ban: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", s_nxb[viTri], 50);
	printf("Vui long nhap Nam Xuat Ban: ");
	scanf_s("%d", &s_namxb[viTri]);
	printf("Vui long nhap The Loai: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", s_theLoai[viTri], 30);
	printf("Vui long nhap Gia Nhap: ");
	scanf_s("%d", &s_giaNhap[viTri]);
	printf("Vui long nhap Gia Ban: ");
	scanf_s("%d", &s_giaBan[viTri]);
	s_tonKho[viTri] = 0; // Khoi tao ton kho ban dau la 0
	// Tu dong tang so luong sach sau khi them moi
	(*s_soLuong)++;
	printf("%s da duoc them vao kho Sach.\n", s_tenSach);
}

//Ham tim sach theo ISBN, ma dau vao phai it hon 13 chu so, chi can co mot doan trung la co the match
// Chuc nang: Tim kiem sach theo chuoi ISBN (ho tro tim chuoi con, khong can go day du 13 so)
// Gia tri tra ve: chi in ket qua ra man hinh)
int TimISBN(char isbn[][15], char tensach[][50], char tacgia[][50], char nxb[][50], int namxb[], char theloai[][30], int gianhap[], int giaban[], int tonkho[], bool isDeletedSach[], int* countSach)
{
    while (getchar() != '\n'); // Xoa bo dem ban phim de khong bi troi lenh nhap chuoi

    printf("\n--- TIM KIEM SACH THEO ISBN ---\n");
    printf("Nhap chuoi ISBN can tim (co the nhap 1 phan): ");
    char isbnIn[15];
    scanf_s("%[^\n]", isbnIn, 15);

    int countKq = 0; // Dem xem tim duoc bao nhieu cuon sach khop

    // Tinh do dai chuoi ISBN vua nhap vao
    int len_isbnIn = 0;
    while (isbnIn[len_isbnIn] != '\0') {
        len_isbnIn++;
    }

    printf("\n>> CAC KET QUA TIM DUOC:\n");
    printf("%-5s | %-15s | %-25s | %-20s | %-15s | %-7s | %-10s | %-8s\n", "STT",
        "ISBN", "Ten Sach", "Tac Gia", "The Loai", "Nam XB", "Gia Ban", "Ton Kho");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    // Quet toan bo danh sach sach trong kho
    for (int i = 0; i < *countSach; i++)
    {
        if (isDeletedSach[i] == false) // Chi tim tren nhung cuon chua bi xoa mem
        {
            bool isMatch = false;

            // Dem do dai ISBN cua cuon sach hien tai trong mang
            int len_isbn = 0;
            while (isbn[i][len_isbn] != '\0') {
                len_isbn++;
            }

            // Chi tim neu chuoi nhap vao khong dai hon ISBN thuc te va khong rong
            if (len_isbnIn <= len_isbn && len_isbnIn > 0) {
                // Thuat toan truot: kiem tra tung doan chuoi con
                for (int j = 0; j <= len_isbn - len_isbnIn; j++) {
                    bool checkMatch = true;

                    // So sanh tung ky tu trong chuoi
                    for (int k = 0; k < len_isbnIn; k++) {
                        if (isbn[i][j + k] != isbnIn[k]) {
                            checkMatch = false; // Sai 1 ky tu la bo qua doan nay ngay
                            break;
                        }
                    }

                    // Neu khop hoan toan chuoi con thi danh dau la da tim thay va thoat vong lap kiem tra
                    if (checkMatch == true) {
                        isMatch = true;
                        break;
                    }
                }
            }

            // Neu tim thay thi in ket qua va tang bien dem
            if (isMatch == true)
            {
                printf("%-15.15s | %-25.25s | %-20.20s | %-15.15s | %-7d | %-10d | %-8d\n",
                    isbn[i], tensach[i], tacgia[i], theloai[i], namxb[i], giaban[i], tonkho[i]);
                countKq++;
            }
        }
    }

    // Neu quet het vong lap ma bien dem van bang 0 tuc la khong co ket qua
    if (countKq == 0) {
        printf(">> Khong tim thay cuon sach nao khop voi chuoi ISBN da nhap!\n");
    }
    return;
}

// Ham chinh sua thong tin sach
void SuaThongTinS(char s_ISBN[][14], char s_tenSach[][100], char s_tacGia[][50], char s_nxb[][50], int s_namxb[], char s_theLoai[][30], int s_giaNhap[], int s_giaBan[], int s_tonKho[], int* s_soLuong)
{
    printf("\n--- CAP NHAT THONG TIN SACH ---\n");
    printf("----------------------------------------\n");
	
    // Goi ham Tim ISBN de chon sach can chinh sua, ham se tra ve ID (index) cua sach duoc chon
    TimISBN()
    // Neu tra ve loi thi dung ham
    if (idpick == -1) {
        return;
    }
    // Neu khong loi, thuc hien chuc nang chinh sua
    int fnpick;
    do {
        printf("Chon thong tin can chinh sua:\n");
        printf("1. Ten Sach\n");
        printf("2. Tac Gia\n");
        printf("3. Nha Xuat Ban\n");
        printf("4. Nam Xuat Ban\n");
        printf("5. The Loai\n");
        printf("6. Gia Nhap\n");
        printf("7. Gia Ban\n");
        printf("8. Ton Kho\n");
        printf("9. Quay lai menu quan ly sach\n");
        printf("Lua chon cua ban (1-9): ");
        scanf_s("%d", &fnpick);
        switch (fnpick) {
        case 1:
            while (getchar() != '\n');
            printf("Vui long nhap Ten Sach moi: ");
            scanf_s("%[^\n]", s_tenSach[idpick], 100);
            break;
        case 2:
            while (getchar() != '\n');
            printf("Vui long nhap Tac Gia moi: ");
            scanf_s("%[^\n]", s_tacGia[idpick], 50);
            break;
        case 3:
            while (getchar() != '\n');
            printf("Vui long nhap Nha Xuat Ban moi: ");
			scanf_s("%[^\n]", s_nxb[idpick
