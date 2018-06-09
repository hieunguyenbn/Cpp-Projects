#include <iostream>
using namespace std;

class Point {

//	int xVal, yVal;
	
	protected:
 	int Tong (int x, int y) {
 		return (x+y);
	 }
	public:
 	void TBC (int a, int b) {
 		
 		cout << Tong(a,b)/2 << endl;
	 }
};

	
int main() {
	
	Point pt;
	pt.TBC(5,5);

// pt.xVal = 10; // Ðúng hay sai?

 return 0;

}
