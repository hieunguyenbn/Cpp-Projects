#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void InSoThuc() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);
	double a = 4.1234567, b = 234.94948902, c = 0.003849954732;
	for (int i = 0; i < 10; i++) {
		cout<<setw(13)<<a<<setw(13)<<b<<setw(13)<<c<<endl;
		a += 11.12908340; b += 120.3949832; c += 3.29403230;
	}
}
void DoiCoSo() {
	int n;
	cout<<"Nhap n = ";
	cin>>hex>>n;
	cout<<"n o he bat phan: "<<oct<<n;
	//cout<<"n o he nhi phan: "<<bin<<n;
	cout<<"n o he thap phan: "<<dec<<n<<endl;

}
void NhanVien(){

	int n, ma[100]; 
	string hoten[100];
	string que[100];
	cout<<"Nhap so luong nhan vien: "; cin>>n;

	for (int i = 1; i <= n; i++) {
		cout<<"Nhap ma nhan vien: "; cin>>ma[i];
		fflush(stdin);
		cout<<"Nhap ten nhan vien: ";
		getline(cin,hoten[i]); 
		getline(cin,hoten[i]); 
		cout<<"Nhap que quan:";
		getline(cin,que[i]);
	}
	
	cout<<"DANH SACH NHAN VIEN CONG TY\n";
	cout<<"	Ngay 22/10/2017\n\n";
	cout<<setw(7)<<left<<"MaNV";
	cout<<setw(25)<<left<<"Ho Ten";
	cout<<setw(25)<<right<<"Que quan";
	cout<<setfill('-');//tao duong ke ngang
	cout<<setw(57)<<'-'<<endl;
	cout<<setfill(' ');
	for (int i = 1; i <= n; i++) {
		cout<<setw(7)<<left<<ma[i];
		cout<<setw(25)<<left<<hoten[i];
		cout<<setw(25)<<right<<que[i]<<endl;
	}

}

int main() {
	InSoThuc();
	DoiCoSo();
	NhanVien();
	return 0;
}