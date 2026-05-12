#include <stdio.h>
#include "qlkh.h"

// Ham xem cac khach hang dang co trong he thong, chi hien thi nhung khach hang chua bi xoa 
void XemDanhSachKH(int idKH[], char hoTen[][50], char sdt[][11], char email[][50], char diaChi[][100], int ngayDk[], int thangDk[], int namDk[], bool isVIP[], bool isDeleted[], int* count)
{
    printf("\n--- DANH SACH KHACH HANG ---\n");

    if (*count == 0) {
        printf("He thong chua co khach hang nao!\n");
		printf("Ban co muon them khach hang moi khong? (1.Co / 2.Khong): ");
        int fnpick;
		scanf_s("%d", &fnpick);
        if (fnpick == 1) {
			ThemKH(idKH, hoTen, sdt, email, diaChi, ngayDk, thangDk, namDk, isVIP, isDeleted, count);
        }
        else {
            return;
		}
    }

    printf("%-5s | %-25s | %-10s | %-20s | %-25s | %-10s | %-5s\n",
        "ID", "Ho va Ten", "SDT", "Email", "Dia Chi", "Ngay DK", "LoaiThe");

    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    // in tung dong du lieu
    for (int i = 0; i < *count; i++)
    {
        if (isDeleted[i] == false)
        {
            printf("%-5d | %-25.25s | %-10.10s | %-20.20s | %-25.25s | %02d/%02d/%04d | %-5s\n",
                idKH[i],
                hoTen[i],
                sdt[i],
                email[i],
                diaChi[i],
                ngayDk[i], thangDk[i], namDk[i],
                isVIP[i] ? "VIP" : "Thuong");
        }
    }
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

// Ham them khach hang moi vao he thong, tu dong tang ID va so luong khach hang sau khi them moi
void ThemKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count)
{
    printf("\n--- THEM KHACH HANG MOI ---\n");

    if (*count >= 100)
    {
        printf("Danh sach khach hang da day. Vui long xoa bot truoc khi tiep tuc\n");
        return;
    }

    int viTri = *count;

    while (getchar() != '\n');
    printf("Vui long nhap Ho va Ten Khach Hang: ");
    scanf_s("%[^\n]", hoten[viTri], 50);

    printf("Nhap So Dien Thoai: ");
    scanf_s("%s", sdt[viTri], 11);

    printf("Nhap Email: ");
    scanf_s("%s", email[viTri], 50);

    while (getchar() != '\n');
    printf("Nhap Dia Chi: ");
    scanf_s("%[^\n]", diachi[viTri], 50);

    printf("Nhap Ngay Dang Ky (dd mm yyyy) cach nhau boi dau cach: ");
    scanf_s("%d %d %d", &ngaydk[viTri], &thangdk[viTri], &namdk[viTri]);

    printf("Loai the cua khach hang (1 = Thuong, 2 = VIP): ");
    int loaiThe;
    scanf_s("%d", &loaiThe);
    isVIP[viTri] = (loaiThe == 2) ? true : false;

	// Tu dong tang ID cho khach hang moi, bat dau tu 1
    idKH[viTri] = viTri + 1;

    isDeleted[viTri] = false;

	// Tu dong tang so luong khach hang sau khi them moi
    (*count)++;

    printf("Khach hang moi da duoc them vao danh sach. (ID cap nhat: %d)\n", idKH[viTri]);
}

//Ham chon khach hang bang ID
int SelectID(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count)
{
    printf("\nChon ID khach hang: ");
    int idpick;
    scanf_s("%d", &idpick);
    idpick = idpick - 1;

    if (idpick < 0 || idpick >= *count || isDeleted[idpick] == true)
    {
        printf(">> Khong tim thay khach hang hoac khach hang da bi xoa.\n");
		return -1; //Bao loi neu ID khong hop le
    }

    // In ra cho nguoi dung xem truoc khi sua/xoa
    printf("\n--- Thong tin cua khach hang ---\n");
    printf("ID: %d | Ho va Ten: %s | SDT: %s\n", idKH[idpick], hoten[idpick], sdt[idpick]);
    printf("Email: %s\n", email[idpick]);
    printf("Dia Chi: %s\n", diachi[idpick]);
    printf("Ngay Dang Ky: %02d/%02d/%04d\n", ngaydk[idpick], thangdk[idpick], namdk[idpick]);
    printf("Loai The: %s\n", isVIP[idpick] ? "VIP" : "Thuong");
    printf("----------------------------------------\n");

    return idpick; // Tra ve ID khach hang duoc chon
}

// Ham chinh sua thong tin khach hang
void SuaThongTinKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count)
{
    printf("\n--- CAP NHAT THONG TIN KHACH HANG ---\n");
    printf("----------------------------------------\n");
    // Goi ham chon ID de chon khach hang can xoa
    int idpick = SelectID(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);

    // Neu tra ve loi thi dung ham
    if (idpick == -1) {
        return;
    }
	// Neu khong loi, thuc hien chuc nang chinh sua
    int fnpick;
    do {
        printf("Chon thong tin can chinh sua:\n");
        printf("1. Ho va Ten\n");
        printf("2. So Dien Thoai\n");
        printf("3. Email\n");
        printf("4. Dia Chi\n");
        printf("5. Loai The\n");
        printf("6. Hoan Thanh\n");
        printf("Lua chon (1-6): ");
        scanf_s("%d", &fnpick);
        while (getchar() != '\n');
            switch (fnpick)
            {
            case 1:
                printf("Nhap Ho va Ten moi: ");
                scanf_s("%[^\n]", hoten[idpick], 50);
                printf("Cap nhat thanh cong!\n");
                break;
            case 2:
                printf("Nhap So Dien Thoai moi: ");
                scanf_s("%s", sdt[idpick], 11);
                printf("Cap nhat thanh cong!\n");
                break;
            case 3:
                printf("Nhap Email moi: ");
                scanf_s("%s", email[idpick], 50);
                printf("Cap nhat thanh cong!\n");
                break;
            case 4:
                printf("Nhap Dia Chi moi: ");
                scanf_s("%[^\n]", diachi[idpick], 100);
                printf("Cap nhat thanh cong!\n");
                break;
            case 5:
                if (isVIP[idpick] == true) {
                    printf("Chuyen khach hang ve thanh vien Thuong? (1.Co / 2.Khong): ");
                }
                else {
                    printf("Nang khach hang len thanh vien VIP? (1.Co / 2.Khong): ");
                }

                int xacNhan;
                scanf_s("%d", &xacNhan);
                if (xacNhan == 1) {
                    isVIP[idpick] = !isVIP[idpick]; // dao nguoc trang thai
                    printf("Loai the da duoc cap nhat.\n");
                }
                else {
                    printf("Loai the khach hang duoc giu nguyen.\n");
                }
                break;
            case 6:
                printf("Quay lai Menu Khach Hang.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
            }
    } while (fnpick != 6);
}

// Ham xoa khach hang
void XoaThongTinKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count)
{
    printf("\n--- XOA THONG TIN KHACH HANG ---\n");

	// Goi ham chon ID de chon khach hang can xoa
    int idpick = SelectID(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP, isDeleted, count);

	// Neu tra ve loi thi dung ham
    if (idpick == -1) {
        return;
    }

	// Neu khong loi, tiep tuc thuc hien chuc nang xoa
    printf("Ban co chac chan muon xoa khach hang nay khong? (1.Co / 2.Khong): ");
    int xacNhan;
    scanf_s("%d", &xacNhan);
    if (xacNhan == 1) {
        isDeleted[idpick] = true;
        printf(">> Khach hang da duoc xoa khoi danh sach.\n");
    }
    else {
        printf(">> Khach hang duoc giu nguyen.\n");
    }
}

//Ham tim kiem khach hang theo so dien thoai
int TimKHTheoSDT(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count)
{
    printf("\n--- TIM KIEM KHACH HANG THEO SO DIEN THOAI ---\n");
    printf("Nhap so dien thoai can tim: ");
    char sdtIn[11];
    scanf_s("%s", sdtIn, 11);

    // Duyet tung khach hang
    for (int i = 0; i < *count; i++)
    {
        // Khong tim khach hang da bi xoa
        if (isDeleted[i] == false)
        {
			bool isMatch = true; //Bien kiem tra tung chu so trong 2 sdt co giong nhau hay khong
            int j = 0;

            // Vong lap so sanh tung ky tu trong 2 chuoi
            while (sdt[i][j] != '\0' || sdtIn[j] != '\0')
            {
                // Nếu phát hiện có chữ số không giống nhau
                if (sdt[i][j] != sdtIn[j]) {
                    isMatch = false; 
                    break;
                }
                j++;
            }

            // Nếu sau vòng lặp while, isMatch vẫn là true -> 2 chuỗi y chang nhau
            if (isMatch == true)
            {
                printf("\n>> KET QUA TIM DUOC:\n");

                printf("%-5s | %-25s | %-10s | %-20s | %-25s | %-10s | %-5s\n",
                    "ID", "Ho va Ten", "SDT", "Email", "Dia Chi", "Ngay DK", "LoaiThe");
                printf("-----------------------------------------------------------------------------------------------------------------------\n");

                printf("%-5d | %-25.25s | %-10.10s | %-20.20s | %-25.25s | %02d/%02d/%04d | %-5s\n",
                    idKH[i],
                    hoten[i],
                    sdt[i],
                    email[i],
                    diachi[i],
                    ngaydk[i], thangdk[i], namdk[i],
                    isVIP[i] ? "VIP" : "Thuong");
                return i;
            }
        }
    }

	// Neu chay het vong lap ma van chua tim thay khach hang nao co so dien thoai trung khop, in ra thong bao va tra ve -1
    printf(">> Khong tim thay khach hang voi so dien thoai da nhap.\n");
    return -1;
}

// Ham tim kiem khach hang theo ten
void TimKHTheoTen(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count)
{
    while (getchar() != '\n'); // Xóa bộ đệm
    printf("\n--- TIM KIEM KHACH HANG THEO TEN ---\n");
    printf("Nhap ten khach hang can tim: ");
    char tenIn[50];
    scanf_s("%[^\n]", tenIn, 50);

    int countKq = 0; // Đếm xem tìm được bao nhiêu người

    // Do dai chuoi nhap vao
    int len_tenIn = 0;
    while (tenIn[len_tenIn] != '\0') {
        len_tenIn++;
    }

    printf("\n>> CAC KET QUA TIM DUOC:\n");
    printf("%-5s | %-25s | %-10s | %-20s | %-25s | %-10s | %-5s\n",
        "ID", "Ho va Ten", "SDT", "Email", "Dia Chi", "Ngay DK", "LoaiThe");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    // Quet toan bo khach hang chua bi xoa
    for (int i = 0; i < *count; i++)
    {
        if (isDeleted[i] == false)
        {
            bool isMatch = false;

			// Dem do dai ten khach hang hien tai
            int len_hoten = 0;
            while (hoten[i][len_hoten] != '\0') {
                len_hoten++;
            }

            // Chi tim neu ten nhap khong dai hon ten khach hang hoac khong rong
            if (len_tenIn <= len_hoten && len_tenIn > 0) {
                for (int j = 0; j <= len_hoten - len_tenIn; j++) {
                    bool checkMatch = true;

					// So sanh tung ky tu trong ten khach va ten can tim, neu sai 1 ky tu thi chuyen qua ID tiep theo
                    for (int k = 0; k < len_tenIn; k++) {
                        if (hoten[i][j + k] != tenIn[k]) {
                            checkMatch = false;
                            break;
                        }
                    }

                    // Tra ve ket qua tim thay
                    if (checkMatch == true) {
                        isMatch = true;
                        break;
                    }
                }
            }

            // Neu tim thay thi in ket qua va tang bien dem
            if (isMatch == true)
            {
                printf("%-5d | %-25.25s | %-10.10s | %-20.20s | %-25.25s | %02d/%02d/%04d | %-5s\n",
                    idKH[i], hoten[i], sdt[i], email[i], diachi[i],
                    ngaydk[i], thangdk[i], namdk[i], isVIP[i] ? "VIP" : "Thuong");
                countKq++; // Tang bien dem
            }
        }
    }

    if (countKq == 0) {
        printf(">> Khong tim thay khach hang nao khop voi ten da nhap!\n");
        return;
    }
    return;
}