#ifndef PHANSO_H
#define PHANSO_H

class PhanSo {
private:
    int iTu;
    int iMau;

    int UCLN(int a, int b);
    int BCNN(int a, int b);

public:
    PhanSo();
    PhanSo(int tu, int mau);

    void   Nhap();
    void   Xuat();
    PhanSo RutGon();
    PhanSo Tong(PhanSo ps);
    PhanSo Hieu(PhanSo ps);
    PhanSo Tich(PhanSo ps);
    PhanSo Thuong(PhanSo ps);
    int    SoSanh(PhanSo ps);  // -1: nhỏ hơn | 0: bằng | 1: lớn hơn
};

#endif
