#ifndef GIOPHUTGIAY_H
#define GIOPHUTGIAY_H

class GioPhutGiay {
private:
    int iGio;
    int iPhut;
    int iGiay;

    void ChuanHoa(); // xử lý tràn khi cộng giây

public:
    GioPhutGiay();
    GioPhutGiay(int gio, int phut, int giay);

    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
};

#endif
