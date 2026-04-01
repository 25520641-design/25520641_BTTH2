#include "GioPhutGiay.h"
#include <iostream>
#include <iomanip>
using namespace std;


GioPhutGiay::GioPhutGiay() : iGio(0), iPhut(0), iGiay(0) {}

GioPhutGiay::GioPhutGiay(int gio, int phut, int giay) {
    iGio  = (gio  >= 0 && gio  <= 23) ? gio  : 0;
    iPhut = (phut >= 0 && phut <= 59) ? phut : 0;
    iGiay = (giay >= 0 && giay <= 59) ? giay : 0;
}

// Chuẩn Hóa
// Xử lý khi giây >= 60 → tăng phút, khi phút >= 60 → tăng giờ
// Giờ được tính theo modulo 24 (đồng hồ 24 giờ)
void GioPhutGiay::ChuanHoa() {
    iPhut += iGiay / 60;
    iGiay  = iGiay % 60;

    iGio  += iPhut / 60;
    iPhut  = iPhut % 60;

    iGio   = iGio  % 24;
}

// Nhập
void GioPhutGiay::Nhap() {
    do {
        cout << "Nhap gio  (0-23): ";
        cin  >> iGio;
    } while (iGio < 0 || iGio > 23);

    do {
        cout << "Nhap phut (0-59): ";
        cin  >> iPhut;
    } while (iPhut < 0 || iPhut > 59);

    do {
        cout << "Nhap giay (0-59): ";
        cin  >> iGiay;
    } while (iGiay < 0 || iGiay > 59);
}

// Xuất
// Hiển thị dạng HH:MM:SS (có số 0 đệm)
void GioPhutGiay::Xuat() {
    cout << setfill('0')
         << setw(2) << iGio  << ":"
         << setw(2) << iPhut << ":"
         << setw(2) << iGiay;
}

// TinhCongThemMotGiay
void GioPhutGiay::TinhCongThemMotGiay() {
    iGiay++;
    ChuanHoa();
}
