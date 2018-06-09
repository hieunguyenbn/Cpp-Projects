//bai 8_file c++1: dung class nhap ma tran mn, in ra mn va tim max
#include<iostream>
#include<iomanip>
using namespace std;

class matran{
	private:
		int i,j, m, n, a[20][20];
	public: 
		void nhap(int a[20][20], int m, int n);
		void xuat(int a[20][20], int m, int n);
		int soMax(int a[20][20], int m, int n);
};

void matran::nhap(int a[20][20], int m, int n){
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			cin>>a[i][j];
		}	
}
void matran::xuat(int a[20][20], int m, int n) {
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cout<<a[i][j]<<setw(4);
		}
		cout<<"\n";
	}
}
int matran::soMax(int a[20][20], int m, int n) {
	int maxa = a[0][0];
	
	for (i = 0; i < m; i++) 
		for (j = 0; j < n; j++) {
			
		if (maxa < a[i][j]) maxa = a[i][j];
	}
	return maxa;
}
class tichMatran: public matran{
	private:
		int i, j, k;
	public:
		void tich();
};
void tichMatran::tich(){
	int a[20][20],  b[20][20],  c[20][20],  m,  n;
	matran tichMatran;
	cout<<"Nhap kich thuoc mang: ";
	cin>>m>>n;
	cout<<"Nhap mang a:\n";
	tichMatran.nhap(a,m,n);
	cout<<"Nhap mang b:\n";
	tichMatran.nhap(b,m,n);
	cout<<"Xuat mang a:\n";
	tichMatran.xuat(a,m,n);
	cout<<"Xuat mang b:\n";
	tichMatran.xuat(b,m,n);
//	cout<<"\nSo lon nhat cua mang a la: "<<tichMatran.soMax(a,m,n);	
	cout<<"\nMa tran tich:\n";
	if(m==n)
 	 	for(i = 0; i < n ; i++)
  		 	for(k = 0; k < n ; k++) {
     			 c[i][k] = 0;
   			  	 for(j = 0; j < n ; j++)
       			  	c[i][k] = c[i][k] + a[i][j]*b[j][k];
  			 }
  	else cout<<"\nThese two matrix cannot be multiplied!"<<endl;
  	tichMatran.xuat(c,m,n);
  		 		
}
int main(void) {
	tichMatran hieu;

	hieu.tich();
//	tichMatran k;
//	cout<<"\nMa tran tich:\n";
//	k.tich(a,b,c,m,n);
	return 0;
}
