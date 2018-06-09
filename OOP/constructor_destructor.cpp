#include <iostream>
using namespace std;

class sinhvien {
private:
	int ID;
	string Name;
	float *Point;
public:
	void output() {
		cout << "ID number: " << ID;
		cout << "\nName: " << Name;
		cout << "\nPoint: " << *Point;
		cout << "\n";
	}
	sinhvien(void);//construtor//batbuoc
	sinhvien(string n, int id, float p);//thamso
	sinhvien(const sinhvien &x) {
		ID = x.ID;
		Name = x.Name;
		Point = new float;
		*Point = *x.Point;
	}
	void change() {
		(*Point)--;
	}
	void address() {
		cout <<"\nADDRESS: " << &Point;
		cout <<"\nVALUE: " << Point;
 	}
 	string getter() {
 		return Name;
 	}
 	void setter(string t) {
 		Name = t;
 	}
	~sinhvien(void) {//khong can neu ko co con tro
		cout << "\nDESTRUCTING!\n";
		delete(Point);
	}//destructor*/
};
sinhvien::sinhvien(void) {
		ID = 14001214;
		Name = "NGUYEN SY HIEU";
		Point = new float;
		*Point = 10;
		cout << "OK" << endl;
}
sinhvien::sinhvien(string n, int id, float p) {
	Name = n;
	ID = id;
	Point = new float;
	*Point = p;
}

int main(int argc, char const *argv[])
{
	sinhvien SV("HIEU", 10231903, 9.8);
	sinhvien sv2(SV);//copy SV vao sv2 
	SV.change();
	SV.output();
	sv2.output();
	cout << "\nSV: "; SV.address();
	cout << "\nsv2: "; sv2.address();
	cout << "\n";
	sinhvien sv1, sv3;
	cout << sv1.getter();
	sv3.setter("NGAT");
	cout << sv3.getter();
	//sv1.output();
	return 0;
}