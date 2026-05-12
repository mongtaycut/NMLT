#pragma once
#include <stdio.h>
#include <stdbool.h>

void XemDanhSachKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count);
void ThemKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count);
void SuaThongTinKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count);
void XoaThongTinKH(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count);
int TimKHTheoSDT(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count);
void TimKHTheoTen(int idKH[], char hoten[][50], char sdt[][11], char email[][50], char diachi[][100], int ngaydk[], int thangdk[], int namdk[], bool isVIP[], bool isDeleted[], int* count);