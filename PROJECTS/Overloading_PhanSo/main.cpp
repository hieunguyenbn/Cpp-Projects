#include <iostream>
#include "PhanSo.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	PhanSo p1, p2, p;
	p1.nhap();
	p2.nhap();
	p = p1 + p2;
	cout << "Phan so thu nhat: "; p1.xuat();
	cout << "Phan so thu hai: "; p2.xuat();
	cout << "Tong = "; p.xuat();
	return 0;
}
