#include <iostream>
#include "PhanSo.h"
using namespace std;

void printKetQua(const char* ten, PhanSo ps) {
    cout << ten << " = ";
    ps.Xuat();
    cout << endl;
}

int main() {
    cout << " TEST 1: Nhap tay " << endl;
    PhanSo a, b;
    cout << "Phan so A: "; a.Nhap();
    cout << "Phan so B: "; b.Nhap();

    printKetQua("A + B", a.Tong(b));
    printKetQua("A - B", a.Hieu(b));
    printKetQua("A * B", a.Tich(b));
    printKetQua("A / B", a.Thuong(b));

    int kq = a.SoSanh(b);
    cout << "A so sanh B: ";
    if      (kq < 0) cout << "A < B";
    else if (kq > 0) cout << "A > B";
    else             cout << "A = B";
    cout << endl;

    cout << "\n TEST 2: Gia tri co dinh" << endl;
    PhanSo p1(1, 2);   // 1/2
    PhanSo p2(1, 3);   // 1/3

    cout << "p1 = "; p1.Xuat(); cout << endl;
    cout << "p2 = "; p2.Xuat(); cout << endl;

    printKetQua("p1 + p2", p1.Tong(p2));    // 5/6
    printKetQua("p1 - p2", p1.Hieu(p2));    // 1/6
    printKetQua("p1 * p2", p1.Tich(p2));    // 1/6
    printKetQua("p1 / p2", p1.Thuong(p2));  // 3/2

    cout << "\n TEST 3: Rut gon " << endl;
    PhanSo p3(6, 9);
    cout << "Truoc rut gon: 6/9" << endl;
    cout << "Sau rut gon: "; p3.RutGon().Xuat(); cout << endl;

    cout << "\n TEST 4: Phan so am " << endl;
    PhanSo p4(-3, 4);
    PhanSo p5(1, 4);
    printKetQua("(-3/4) + (1/4)", p4.Tong(p5));   // -1/2
    printKetQua("(-3/4) * (1/4)", p4.Tich(p5));   // -3/16

    return 0;
}
