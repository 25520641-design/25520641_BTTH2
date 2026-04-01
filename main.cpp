#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

int main() {
    //  Nhập tay
    cout << " TEST 1: Nhap tay " << endl;
    GioPhutGiay t1;
    t1.Nhap();
    cout << "Gio vua nhap : "; t1.Xuat(); cout << endl;
    t1.TinhCongThemMotGiay();
    cout << "Cong 1 giay  : "; t1.Xuat(); cout << endl;

    //  Cộng giây bình thường
    cout << "\n TEST 2: Cong giay binh thuong " << endl;
    GioPhutGiay t2(10, 20, 30);
    cout << "Truoc: "; t2.Xuat(); cout << endl;
    t2.TinhCongThemMotGiay();
    cout << "Sau  : "; t2.Xuat(); cout << endl;
    // Kết quả mong đợi: 10:20:31

    // Giây tràn sang phút
    cout << "\n TEST 3: Giay tran sang phut" << endl;
    GioPhutGiay t3(10, 20, 59);
    cout << "Truoc: "; t3.Xuat(); cout << endl;
    t3.TinhCongThemMotGiay();
    cout << "Sau  : "; t3.Xuat(); cout << endl;
    // Kết quả mong đợi: 10:21:00

    //  Phút tràn sang giờ
    cout << "\n===== TEST 4: Phut tran sang gio =====" << endl;
    GioPhutGiay t4(10, 59, 59);
    cout << "Truoc: "; t4.Xuat(); cout << endl;
    t4.TinhCongThemMotGiay();
    cout << "Sau  : "; t4.Xuat(); cout << endl;
    // Kết quả mong đợi: 11:00:00

    //  Giờ tràn quá nửa đêm  (23:59:59 + 1s)
    cout << "\n===== TEST 5: Qua nua dem =====" << endl;
    GioPhutGiay t5(23, 59, 59);
    cout << "Truoc: "; t5.Xuat(); cout << endl;
    t5.TinhCongThemMotGiay();
    cout << "Sau  : "; t5.Xuat(); cout << endl;
    // Kết quả mong đợi: 00:00:00

    // Cộng nhiều lần liên tiếp
    cout << "\n===== TEST 6: Cong 5 giay lien tiep =====" << endl;
    GioPhutGiay t6(0, 0, 57);
    cout << "Bat dau: "; t6.Xuat(); cout << endl;
    for (int i = 1; i <= 5; i++) {
        t6.TinhCongThemMotGiay();
        cout << "Sau " << i << " giay: "; t6.Xuat(); cout << endl;
    }
    // Kết quả mong đợi: 00:01:02

    return 0;
}
