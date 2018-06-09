#include <iostream>
using namespace std;
#define pi 3.1415926536
void hinhtron(const double &r, double &chuvi, double &dientich);
int main() {

	double bien = 2.2;
	double &b = bien;

	cout<<"lan 1: "<<bien<<" "<<b<<endl;
	bien += 1;
	cout<<"lan 2: "<<bien<<" "<<b<<endl;
	b += 1;
	cout<<"lan 3: "<<bien<<" "<<b<<endl;

	double bk = 4.5, cv, dt;
	cout<<"Dia chi cua bk la: "<<&bk<<endl;
	cout<<"Dia chi cua cv va dt la: "<<&cv<<" "<<&dt<<endl;
	hinhtron(bk,cv,dt);
	cout<<"cv = "<<cv<<" "<<"dt = "<<dt<<endl;
	cout<<"Ban kinh hinh tron ra khoi ham la: "<<bk<<endl;
	return 0;
}
void hinhtron(const double &r, double &chuvi, double &dientich) {

	cout<<"&chuvi = "<<&chuvi
		<<" &dientich = "<<&dientich<<endl;
	cout<<"&r = "<<&r<<" "<<"r = "<<r<<endl;
	chuvi = 2.0*pi*r;
	dientich = pi*r*r;
	//r = 2.0*r;
	cout<<"chuvi = "<<chuvi<<" "<<"dientich = "<<dientich<<endl;
}