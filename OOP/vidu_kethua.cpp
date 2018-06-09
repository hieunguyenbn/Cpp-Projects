#include <iostream>
#include<stdio.h>
#include <string> 
using namespace std;

// lop cha
class Nguoi
{
	protected:
	char hoTen[30];
	int namSinh;
	private:
	char soThich[50]; // so thich
	public:
	Nguoi(){ // khoi tao lop Nguoi
	strcpy(hoTen,"Nguyen Van A");
	namSinh=1990;
	strcpy(soThich,"Lap trinh");
}
void InTT(); // In thông tin
};
// lop con
class HocSinh : public Nguoi
{
	protected:
	int maHS;
	public:
	void Nhap();
	void InTT();
};
	// InTT cua cha (Nguoi)
	void Nguoi::InTT()
	{
	cout << "\n Nam sinh : " << namSinh;
	cout << "\n Ho ten : " << hoTen;
	cout << "\n So thich : " << soThich;
	}
	// InTT cua con (HocSinh)
void HocSinh::InTT()
	{
	cout << "\n Ma hoc sinh : " << maHS;
	cout << "\n Nam sinh : " << namSinh;
	cout << "\n Ho ten : " << hoTen;
	}
	// Nhap thong tin
	void HocSinh::Nhap()
	{
	cout << "\n Nam sinh : "; cin>> namSinh;
	cout << "\n Ho ten : "; cin.ignore(1);
	cin.getline(hoTen,10);
	cout << "\n Ma hoc sinh: "; cin>> maHS;
}

// ham main ---------------------------------------------
int main(){

	// khai bao doi tuong Nguoi
	Nguoi a; a.InTT();
	// khai bao doi tuong HocSinh
	HocSinh t; t.Nhap(); t.InTT();

	return 0;
}