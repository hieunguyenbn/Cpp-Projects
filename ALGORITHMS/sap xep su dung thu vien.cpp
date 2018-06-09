#include <iostream>
#include <algorithm>

using namespace std;

class Nguoi {
    private:
        string ten;
        int tuoi;
        string quequan;
    public:
        void NhapDuLieu();
        void HienThiThongTin();

        friend class SoSanhTangDanVeTuoi;
        friend class SoSanhTangDanVeQueQuan;
};

void Nguoi::NhapDuLieu() {
    cout << "     Ho ten: "; getline(cin, ten);
    cout << "     Tuoi: "; cin >> tuoi;
    cin.ignore(1);
    cout << "     Que quan: "; getline(cin, quequan);
}

void Nguoi::HienThiThongTin() {
    cout << "Ho ten:   " << ten << endl;
    cout << "Tuoi  :   " << tuoi << endl;
    cout << "Que quan: " << quequan << endl;
    cout << endl;
}

class SoSanhTangDanVeTuoi {
    public:
        bool operator()(Nguoi nguoi1, Nguoi nguoi2) {
            if (nguoi1.tuoi < nguoi2.tuoi) return true;
                else return false;
        }
};

class SoSanhTangDanVeQueQuan {
    public:
        bool operator()(Nguoi nguoi1, Nguoi nguoi2) {
            if (nguoi1.quequan < nguoi2.quequan) return true;
                else return false;
        }
};

int main() {
    const int MAXN = 5;
    Nguoi dscongty[MAXN];
    int n = MAXN;
    int i;
    for (i=0; i<n; i++) {
        cout << "Nhap thong tin nhan vien thu " << i+1 << ": " << endl;
        dscongty[i].NhapDuLieu();
    }

    //sort(dscongty, dscongty+n, SoSanhTangDanVeTuoi());
    sort(dscongty, dscongty+n, SoSanhTangDanVeQueQuan()); // Sap xep co dieu kien


    cout << endl << "Hien thi danh sach nhan vien cua cong ty sau khi sap xep:" << endl;
    for (i=0; i<n; i++)
        dscongty[i].HienThiThongTin();
}
