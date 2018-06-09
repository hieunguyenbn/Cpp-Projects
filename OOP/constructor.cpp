#include <iostream>
using namespace std;

class hinh {
private:
	int dai;
	int rong;
public:
	hinh(int chieudai, int chieurong) {
		dai = chieudai;
		rong = chieurong;
	}
	int chuvi(void) {
		return 2*(dai+rong);
	}
	int dientich(void) {
		return dai*rong;
	}
};
int main() {

	hinh h1(10,10);
	cout << h1.chuvi() << endl;
	cout << h1.dientich() << endl;
	return 0;
}