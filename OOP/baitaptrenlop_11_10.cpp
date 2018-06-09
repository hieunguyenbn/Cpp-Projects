#include <iostream>
using namespace std;


void inputArray(int a[20][20], int m, int n);
void outputArray(int a[20][20], int m, int n);
void xuly(int a[20][20], int m, int n);

int main() {
	
	int a[20][20], m, n;
	cin>>m>>n;
	inputArray(a,m,n);
	outputArray(a,m,n);
	xuly(a,m,n);
	
	return 0;
}
void inputArray(int a[20][20], int m, int n) {
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin>>a[i][j];
		}
	
}
void outputArray(int a[20][20], int m, int n) {
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cout<<a[i][j]<<" ";
			if (j==n-1) cout<<endl;
		}
	
}
void xuly(int a[20][20], int m, int n) {
	int amin = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
		//	if (i == j) cout<<a[i][j]<<endl;
				if (a[i][j]>0) {
					
				 	amin = a[i][j];//find the first plus number
						break;
				
				}
				
		}
	if (amin == 0) cout<<"Khong co so duong trong mang nay!"<<endl;
	for (int i = i; i < m; i++)
		for (int j = j; j < n; j++) {
			 if (a[i][j] > 0 && a[i][j] < amin)
					amin = a[i][j];
		}
	cout << amin << endl;
}
