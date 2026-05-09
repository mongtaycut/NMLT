#pragma once

#include <stdbool.h>

#define MAX_KH 500
#define MAX_HOTEN 50
#define MAX_SDT 15
#define MAX_EMAIL 50
#define MAX_DIACHI 100

void HienThiMenu(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int *soLuongKH, int *nextID);
void XemDanhSachKH(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH);
bool ThemKhachHang(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int *soLuongKH, int *nextID);
bool SuaThongTinKH(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH);
bool XoaThongTinKH(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int *soLuongKH);
void TimKHTheoSDT(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH);
void TimKHTheoTen(int idKH[MAX_KH], char hoten[MAX_KH][MAX_HOTEN], char sdt[MAX_KH][MAX_SDT], char email[MAX_KH][MAX_EMAIL], char diachi[MAX_KH][MAX_DIACHI], int ngaydk[MAX_KH], int thangdk[MAX_KH], int namdk[MAX_KH], bool isVIP[MAX_KH], int soLuongKH);