#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct Sinhvien {
	string hoten;
	char maSV[20];
	float diemTB;
	struct ngaysinh{
		int ngay, thang, nam;
	}ns;
};
int main(int argc, char const *argv[]) {
	
	Sinhvien k59qtvl[50];
	int n;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout << "Nhap vao so sinh vien: "; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin.ignore();
		cout << "Nhap vao ten sinh vien thu " << i << ": ";
		cin.ignore();
		getline(cin,k59qtvl[i].hoten);
		cout << "Nhap vao ma sinh vien: ";
		//if (fgets(k59qtvl[i].maSV,20,stdin) != NULL);
		fgets(k59qtvl[i].maSV,20,stdin);
		cout << "Nhap vao diem trung binh: ";
		cin >> k59qtvl[i].diemTB;
		cout << "Nhap vao ngay thang nam sinh: ";
		cin >> k59qtvl[i].ns.ngay >> k59qtvl[i].ns.thang >> k59qtvl[i].ns.nam;
	}
	cout << "DANH SACH SINH VIEN LOP K59 QTVL" << endl;
	cout << setw(20) << left << "Ho Ten" ;
	cout << setw (14) << left << "MA SV";
	cout << setw(7) << left << "Diem";
	cout << setw(10) << right << "NS"<<endl;
	//cout << setfill(' ');
//	cout << setw(40) << "_" << endl;
	//cout << setfill(' ') << endl;
	for (int i = 1; i <= n; i++) {
		cout << setw(20) << left << k59qtvl[i].hoten;
		cout << setw(14) << left << k59qtvl[i].maSV;
		cout << setw(7) << left << k59qtvl[i].diemTB;
		cout << setw(10) << right << k59qtvl[i].ns.ngay;
		cout << "/" << k59qtvl[i].ns.thang << "/" << k59qtvl[i].ns.nam;
		//cout <<"\n";
	}
	cout <<"\n";
	FILE *danhsach = NULL;
	danhsach = fopen("sv.txt","w+");
	if (danhsach != NULL) {
		for (int i = 1; i <= n; i++) {
			fputs("DANH SACH SINH VIEN",danhsach);
			fprintf(danhsach,"sinh vien %s Ma %s  Diem %f", k59qtvl[i].hoten, k59qtvl[i].maSV, k59qtvl[i].diemTB);
		}
		fclose(danhsach);
	}
	else cout<<"cannot use this file!"<<endl;
	return 0;
}
