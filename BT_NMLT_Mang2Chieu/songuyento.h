#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Hàm kiểm tra số nguyên tố
inline bool KiemTraNguyenTo(int n) {
    if (n <= 1) return false; // Số nhỏ hơn hoặc bằng 1 không phải số nguyên tố
    if (n == 2) return true;  // 2 là số nguyên tố
    if (n % 2 == 0) return false; // Số chẵn > 2 không phải số nguyên tố

    // Kiểm tra các ước số lẻ từ 3 đến sqrt(n)
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}