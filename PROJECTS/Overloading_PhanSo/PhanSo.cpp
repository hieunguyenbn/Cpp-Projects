#include "PhanSo.h"
#include <iostream>
using namespace std;
PhanSo::PhanSo()
{
	mau = 1;
}
void PhanSo::nhap() {
	cout << "\nNhap tu so: ";
	cin >> tu;
	do {
		cout << "\nNhap mau so: ";
		cin >> mau;
	} while (!mau);
}
void PhanSo::xuat() {
	cout << tu << "/" << mau << endl;
}
PhanSo PhanSo::operator +(PhanSo &p1) {
	PhanSo p;
	p.tu = this->tu*p1.mau + this->mau*p1.tu;
	p.mau = this->mau*p1.mau;
	return p;
}
PhanSo::~PhanSo()
{
}
