#include <iostream>
#include <string>
using namespace std;
float tien;
class VeTau {
	public:
		string ten, loaiVe;
		int namPhatHanh;
		float giaGoc;
	public:
		void khoiTao();
		virtual float tienGiamGia() {
			cout << "DIEN TICH: ";
			return 0;
		};
		void thongTin();
};
void VeTau::khoiTao() {
	cout << "Nhap ten ve: ";
	cin.ignore(); getline(cin,ten);
	cout << "Loai ve ?";
	cin.ignore(); getline(cin,loaiVe);
	cout << "Nam phat hanh: ";
	cin >> namPhatHanh;
	cout << "Gia tien goc: ";
	cin >> giaGoc;
}
void VeTau::thongTin() {
	cout << ten << endl;
	cout << loaiVe << endl;
	cout << namPhatHanh << " " << giaGoc << endl;
}
class VeNgoiCung:public VeTau {
	private:
		int soVe;
	public:
		void nhapSove(){
			cout << "Nhap so ve: ";
			cin >> soVe;
		}
		float tienGiamGia() {
			if (soVe <= 50) tien = giaGoc*0.03;
			else tien = giaGoc*0.05;
			cout << "Tien duoc giam: " << tien <<endl;
		}
		void xuat1() {
			cout << "So ve: " << soVe << endl;
			tienGiamGia();
		}
};
class VeNgoiMem:public VeTau {
	private:
		int loaiGhe;
	public:
		void nhapLoaighe() {
			cout << "Nhap loai ghe: ";
			cin >> loaiGhe;
		}
		float tienGiamGia() {
			if (loaiGhe == 1) tien = giaGoc*0.02;
			else tien = giaGoc*0.04;
			cout << "Tien duoc giam: " << tien <<endl;
		}
		void xuat2() {
			cout << "Loai ghe: " << loaiGhe << endl;
			tienGiamGia();
		}
};

class VeGiuongNam:public VeTau {

	public:
		float tienGiamGia() {
			if (giaGoc <= 600 ) tien = giaGoc*0.06;
			else if (giaGoc > 600 && giaGoc < 1200) tien = giaGoc*0.04;
			else tien = giaGoc*0.07;
			cout << "Tien duoc giam: " << tien <<endl;
		}
		void xuat3() {
			tienGiamGia();
		}
		
};

int main () {
	
	VeTau ve1;
	ve1.khoiTao();
	ve1.thongTin();
	return 0;
}
