#include "PhanSo.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
PhanSo::PhanSo() : iTu(0), iMau(1) {}

PhanSo::PhanSo(int tu, int mau) {
    iTu  = tu;
    iMau = (mau == 0) ? 1 : mau;
}

// Private helpers
int PhanSo::UCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int PhanSo::BCNN(int a, int b) {
    return abs(a * b) / UCLN(a, b);
}

// Nhap / Xuat
void PhanSo::Nhap() {
    cout << "Nhap tu so: ";
    cin  >> iTu;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin  >> iMau;
    } while (iMau == 0);
}

void PhanSo::Xuat() {
    PhanSo rg = RutGon();
    if (rg.iMau == 1)
        cout << rg.iTu;
    else
        cout << rg.iTu << "/" << rg.iMau;
}

// RutGon
PhanSo PhanSo::RutGon() {
    int g = UCLN(abs(iTu), abs(iMau));
    int tu  = iTu  / g;
    int mau = iMau / g;
    // Chuẩn hoá: mẫu luôn dương
    if (mau < 0) { tu = -tu; mau = -mau; }
    return PhanSo(tu, mau);
}

// Tong
PhanSo PhanSo::Tong(PhanSo ps) {
    int mauChung = BCNN(iMau, ps.iMau);
    int tu = iTu * (mauChung / iMau) + ps.iTu * (mauChung / ps.iMau);
    return PhanSo(tu, mauChung).RutGon();
}

// Hieu
PhanSo PhanSo::Hieu(PhanSo ps) {
    int mauChung = BCNN(iMau, ps.iMau);
    int tu = iTu * (mauChung / iMau) - ps.iTu * (mauChung / ps.iMau);
    return PhanSo(tu, mauChung).RutGon();
}

// Tich
PhanSo PhanSo::Tich(PhanSo ps) {
    return PhanSo(iTu * ps.iTu, iMau * ps.iMau).RutGon();
}

// Thuong
PhanSo PhanSo::Thuong(PhanSo ps) {
    // Chia = nhân với nghịch đảo
    return PhanSo(iTu * ps.iMau, iMau * ps.iTu).RutGon();
}

// SoSanh
int PhanSo::SoSanh(PhanSo ps) {
    // Quy đồng rồi so sánh tử
    int mauChung = BCNN(iMau, ps.iMau);
    int tu1 = iTu * (mauChung / iMau);
    int tu2 = ps.iTu * (mauChung / ps.iMau);
    if (tu1 < tu2) return -1;
    if (tu1 > tu2) return  1;
    return 0;
}
