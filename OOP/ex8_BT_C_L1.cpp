//ex8
#include <iostream>
using namespace std;

class matran{
	private:
		int i, j, m, n, maxn;
	protected:
		void input();
	public:
		void allocate(int *&a);
		void inputArray(int *&a);
		void outputArray(
		int *&a);
		int maxa(int *&a);
};

void matran::input() {
	cout << "Enter number of elements: ";
	cin >> m >> n;
}
void matran::allocate(int *&a) {
	input();
	a = new int[m*n];
}
void matran::inputfArray(int *&a) {
	cout << "Enter you matrix: ";
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			cin >> a[i*n+j];
		}
}
void matran::outputArray(int *&a) {
	cout << "Your matrix is: " << endl;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			cout << a[i*n+j] << " ";
			if (j==n-1) cout << "\n";
		}

}
int matran::maxa(int *&a) {
	maxn = a[0];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			if (a[i*n+j] > maxn)
				maxn = a[i*n+j];
		}
	return maxn;
}

int main() {
	matran matrix;
	int *p1;
	matrix.allocate(p1);
	matrix.inputArray(p1);
	matrix.outputArray(p1);
	cout << "\nThe biggest number is: " << matrix.maxa(p1) << endl;
	delete []p1;	
}
