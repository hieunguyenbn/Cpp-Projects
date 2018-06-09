#include <iostream>
#include <iomanip>
using namespace std;
 // Thu vien dung de dinh dang thong tin can in ra man hinh
int main() {
	int a[10][10],b[100] ;
	int m, n, i, j,dem,k ; // m,n: so hang, so cot cua ma tran
	bool ok;
	// Nhap gia tri cho cac phan tu cua ma tran 
	cout<<"Nhap m va n: "; 
	cin>>m>>n;
	for (i=0; i<m; i++)
	   	for (j=0; j<n; j++)	{
			cout << "a[" << i << "," << j << "] = " ; 
			cin >> a[i][j] ;
		}
	// Xuat du lieu ra man hinh
	cout << "Ma tran da nhap: \n" ;
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)	{
		cout << setw(6) << a[i][j];
		if (j==n-1) cout << "\n";
		}
	// In ra man hinh Day cac so co mat trong ma tran
	cout<<"Day cac so co mat trong ma tran: ";
	dem=0;
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)	{
			ok=true;
			for (k=0;k<dem;k++)
			if (b[k]== a[i][j]) 
			{
			ok=false;
			break;
			}
	if (ok) {
		cout<<a[i][j]<<" ";
		b[dem]=a[i][j];
		dem++;
		}
	}
	//system("pause");
	return 0;
}
