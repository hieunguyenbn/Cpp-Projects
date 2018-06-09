#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class congnhan{
	protected:
	    string hoten;
        string diachi;
        string vitrilamviec;
    public:
	    void nhap();
		void xuat();    
	    virtual	double tinhluong()=0;
};
void congnhan::nhap(){
	fflush(stdin);
	cout<<"nhap ho ten nhan vien: ";
	getline(cin,hoten);
	cout<<"nhap dia chi: ";
	getline(cin,diachi);
	cout<<"nhap vi tri lam viec: ";
	getline(cin,vitrilamviec);
}
void congnhan::xuat(){
	cout<<setw(15)<<"ho ten"<<setw(15)<<"dia chi"<<setw(15)<<"vi tri"<<setw(15)<<"luong thang"<<endl;
	cout<<setw(15)<<hoten<<setw(15)<<diachi<<setw(15)<<vitrilamviec<<setw(15)<<tinhluong()<<"\n\n";
}
class laptrinhvien:public congnhan{
	private:
	    double hesoluong;
		double luongcoban;
		double  tienthuong;
		double  tiencong;
	public:
	    void sethesoluong_tiencong();
	    double tinhluong();	
};
void laptrinhvien::sethesoluong_tiencong(){
		congnhan::nhap();
	do{
		cout<<"nhap he so luong: ";
		cin>>hesoluong;
		if(hesoluong<=0 || hesoluong>=15){
			cout<<"he so luong khong hop le,nhap lai: "<<endl;
		}
	}while(hesoluong<=0 || hesoluong>=15);
	cout<<"nhap tien cong: ";
	cin>>tiencong;
}
double laptrinhvien::tinhluong(){
	double luongcoban=650000;
	if(tiencong>=24){
		tienthuong=5000000;
	}else{
		tienthuong=3000000;
	}
	return (hesoluong*luongcoban+tienthuong);
}
class nhanvienkinhdoanh:public congnhan{
	private:
		double hoahong;
		double tonggiatrihopdong;
		double phantramhoahong;
	public:
	    void settonggiatrihopdong();
		double tinhluong();	
};
void nhanvienkinhdoanh::settonggiatrihopdong(){
	congnhan::nhap();
	cout<<"nhap tong gia tri hop dong: ";
	cin>>tonggiatrihopdong;
}
double nhanvienkinhdoanh::tinhluong(){
	double luongcoban=650000;
	if(tonggiatrihopdong>1000000000){
		phantramhoahong=0.01;
		hoahong=tonggiatrihopdong*phantramhoahong;
	}else{
		phantramhoahong=0.005;
		hoahong=tonggiatrihopdong*phantramhoahong;
	}
	return (luongcoban+hoahong);
}
main(){	
laptrinhvien ltv;
ltv.sethesoluong_tiencong();
ltv.xuat();

nhanvienkinhdoanh nvkd;
nvkd.settonggiatrihopdong();
nvkd.xuat();
return 0;
}

