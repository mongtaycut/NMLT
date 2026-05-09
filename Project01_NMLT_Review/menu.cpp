#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "source.cpp"

int main()
{
    char menupick,fnpick;
    printf("PHAN MEM QUAN LY NHA SACH");
    printf("Chon MENU");
    printf("1. Quan ly khach hang");
    printf("2. Quan ly sach");
    printf("3. Lap hoa don ban hang");
    printf("4. Quan ly kho");
    printf("5. Thong ke");
    printf("6. Thoat phan mem");
    
    printf("Chon hang muc:");
    scanf("%d", &menupick); 
    if (menupick == 1)
    {
    	printf("a. Xem danh sach khach hang");
        printf("b. Them khach hang moi");
        printf("c. Chinh sua thong tin khach hang");
        printf("d. Xoa thong tin khach hang");
        printf("e. Tim khach hang theo so dien thoai");
        printf("f. Tiem kiem khach hang theo ho ten")
        printf("g. Quay lai menu chinh");
        printf("Lua chon cua ban la:");
        scanf("%d", &fnpick);
        if (fnpick == 'a')
        {
            XemDanhSachKH(idKH, hoten, sdt, email, diachi, ngaydk, thangdk, namdk, isVIP);
        }

        //else if (fnpick == 'b')
        //	NhapKH();
        //else if (fnpick == 'c')
        //    SuaThongTinKH();
        //else if (fnpick == 'd')
        //    XoaThongTinKH();
        //else if
    }
    return 0;
}
    
