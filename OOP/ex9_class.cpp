#include <iostream> 
#include <string> 
#include <iomanip>
#include <cstring>
using namespace std;

class Sinhvien{
	private:
		int n;
		char MaSV[10],Hoten[25],GT[5],NS[15];
		float DTA,DMMT,DNNC,DCTDL,DLTWeb;
	public:
		void NhapDL();
		void HienthiDL();
		void HienthiDSSVTN();

};

Sinhvien x,CTU[80];

inline void Sinhvien::NhapDL(){
		
	int i;
	cout<<"Nhap so sinh vien cua lop: ";
	cin>>n;
	for (i=1; i<=n; i++) 
	{
		cout << "Nhap thong tin cua sinh vien thu " << i;
		cin.ignore(1);
		cout << "\nMaSV: " ; cin.getline(x.MaSV, 10);
		cout << "Ho ten: " ; cin.getline(x.Hoten, 20);
		cout << "Gioi tinh: " ; cin.getline(x.GT, 5);
		cout << "Ngay sinh: " ; cin.getline(x.NS, 15);
		cout << "Diem Tieng Anh: " ; cin >> x.DTA ;
		cout << "Diem Mang May tinh: " ; cin >> x.DMMT ;
		cout << "Diem Ngon ngu C: " ; cin >> x.DNNC ;
		cout << "Diem Cau truc du lieu: " ; cin >> x.DCTDL ;
		cout << "Diem Lap trinh Web: " ; cin >> x.DLTWeb ;
		CTU[i]=x;
	}
}

inline void Sinhvien::HienthiDL(){
	
	int i;
	cout<<"Thong tin ve nhung sinh vien da nhap: \n";
///////////* Trinh bay dong tieu de *//////////////
	cout <<"MaSV"<<setw(10-strlen("MaSV"))<<" ";
	cout <<"HoTen"<<setw(20-strlen("HoTen"))<<" ";
	cout <<"GT"<<setw(5-strlen("GT"))<<" ";
	cout <<"NS"<<setw(15-strlen("NS"))<<" ";
	cout <<"DTA"<<"\t";
	cout <<"DMMT"<<"\t";
	cout <<"DNNC"<<"\t";
	cout <<"DCTDL"<<"\t";
	cout <<"DLTWeb"<<"\t";
	cout<<"\n";
//////////* Hien thi thong tin cua tung sinh vien *////////////
	for (i=1; i<=n; i++) 
	{
		x=CTU[i];

		cout <<x.MaSV<<setw(10-strlen(x.MaSV))<<" ";
		cout <<x.Hoten<<setw(20-strlen(x.Hoten))<<" ";
		cout <<x.GT<<setw(5-strlen(x.GT))<<" ";
		cout <<x.NS<<setw(15-strlen(x.NS))<<" ";
		cout <<x.DTA<<"\t";
		cout <<x.DMMT<<"\t";
		cout <<x.DNNC<<"\t";
		cout <<x.DCTDL<<"\t";
		cout <<x.DLTWeb<<"\t";
		cout<<"\n";
	}
  
}

int main(){

	x.NhapDL();
	x.HienthiDL();
	return 0;
	
}