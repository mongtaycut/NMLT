#include <stdio.h>
#include <math.h>
#include "mang.h"
#include "songuyento.h" // Nhớ đảm bảo bạn có file này và có hàm KiemTraNguyenTo nhé

void NhapMang(int arr[100], int &n)
{
    printf("Nhap so luong phan tu mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n ; i++)
    {
        printf("Nhap phan tu [%d]: ", i);
        scanf("%d", &arr[i]); // Sửa printf thành scanf
    }
}

void XuatMang(int arr[100], int n)
{
    printf("\nCac phan tu trong mang la:\n");
    for (int i = 0; i < n ; i++)
    {
        printf("%5d", arr[i]);
    }
    printf("\n"); 
}

int TinhTong(int arr[100], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    return s; // Sửa return 0 thành return s
}

int ViTriNhoNhat(int arr[100], int n)
{
    int min = 0; // min lưu vị trí
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i; // Cập nhật lại vị trí
        }
    }
    return min; // Thêm return
}

int DemSoNguyenTo(int arr[100], int n) // Thêm int trước n
{
    int dem = 0;
    for (int i = 0; i < n ; i++)
    {
        if (arr[i] < 100 && KiemTraNguyenTo(arr[i]))
        {
            dem++;
        }
    }
    return dem;
}

//Bài 136: Tìm số chẵn cuối cùng trong mảng 1 chiều các số nguyên.
int SoChanCuoi(int arr[100], int n) // Thêm int trước n
{
    for (int i = n - 1; i >= 0 ; i--)
    {
        if (arr[i] % 2 == 0) // Kiểm tra phần tử trong mảng
        {
            return arr[i]; // Tìm thấy thì trả về luôn
        }
    }
    return -1; // Duyệt hết mảng không thấy thì trả về -1
}

//Bài 150: Hãy tìm giá trị âm lớn nhất trong mảng 1 chiều các số thực. Nếu mảng không có giá trị âm thì trả về  -1
int PhanTuAmLonNhat(int arr[100], int n)
{
    int maxAm = -1; // Initialize to -1, will be updated if negative found
    bool hasNegative = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (!hasNegative || arr[i] > maxAm)
            {
                maxAm = arr[i];
                hasNegative = true;
            }
        }
    }
    return hasNegative ? maxAm : -1;
}
//Bài 248: Kiểm tra mảng có tăng dần hay không
int KiemTraMangTang(int arr[100], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1]) // Nếu phần tử hiện tại lớn hơn phần tử kế tiếp
        {
            return 0; // Mảng không tăng dần
        }
    }
    return 1; // Mảng tăng dần
}

//Bài 266: Thêm 1 phần tử x vào mảng tại vị trí k
int ThemPhanTuVaoMang(int arr[100], int &n, int x, int vt)
{
    if (vt < 0 || vt > n || n >= 100) {
        return 0;
    }
    for (int i = n; i > vt; i--) {
        arr[i] = arr [i -1];
    }
    arr[vt] = x;
    return 1;
}
