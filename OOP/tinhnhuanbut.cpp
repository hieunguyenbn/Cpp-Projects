#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class sach{
	protected:
		string tensach;
		int namxuatban;
		long long giabia;
		long long soluongphathanh;
	public:
	    void khoitao();
		void inthongtin();
};
void sach::khoitao(){
	
	cin.ignore();	
	cout<<"nhap ten sach: ";
	getline(cin,tensach);
	cout<<"nhap nam xuat ban: ";
	cin>>namxuatban;
	cout<<"nhap gia bia: ";
	cin>>giabia;
	cout<<"nhap so luong phat hanh: ";
	cin>>soluongphathanh;
}
void sach::inthongtin(){
	cout<<setw(15)<<tensach<<setw(10)<<namxuatban<<setw(10)<<giabia<<setw(10)<<soluongphathanh<<endl;
}

class sachgiaokhoa:public sach{
	public:
		long long tinhnhuanbutsachgiaokhoa();
};
long long sachgiaokhoa::tinhnhuanbutsachgiaokhoa(){
	long long tiennhuanbut;
	if(soluongphathanh>2000){
		tiennhuanbut=0.06*giabia*soluongphathanh;
	}else{
		tiennhuanbut=0.08*giabia*soluongphathanh;
	}
	cout<<"tien_nhuan_but = "<<tiennhuanbut<<endl;
}
class sachbaitap:public sach{
	private:
		int sotap;
	public:
		void setsotap();
		int getsotap();
		 long long tinhnhuanbutsachbaitap();
};
int sachbaitap::getsotap(){
	return sotap;
}
void sachbaitap::setsotap(){
	int k;
	cout<<"nhap so tap: ";
	cin>>k;
	sotap=k;
}
long long sachbaitap::tinhnhuanbutsachbaitap(){
		long long tiennhuanbut;
		if(sotap==1){
			tiennhuanbut=0.05*giabia*soluongphathanh;
		}else if(sotap==2){
			tiennhuanbut=0.06*giabia*soluongphathanh;
		}else{
			tiennhuanbut=0.08*giabia*soluongphathanh;
		}
		cout<<"tien_nhuan_but = "<< tiennhuanbut<<endl;
}
class sachthamkhao:public sach{
	private:
		int sotrang;
	public:
		int getsotrang();
		void setsotrang();
	    long long tinhnhuanbutsachthamkhao();
};
int sachthamkhao::getsotrang(){
	return sotrang;
}
void sachthamkhao::setsotrang(){
	int p;
	cout<<"nhap so trang: ";
	cin>>p;
	sotrang=p;
}
long long sachthamkhao::tinhnhuanbutsachthamkhao(){
	long long tiennhuanbut;
		if(sotrang>=500 && soluongphathanh>2000){
			tiennhuanbut=0.08*giabia*soluongphathanh;
		}else{
			tiennhuanbut=0.06*giabia*soluongphathanh;
		}
		cout<<"tien_nhuan_but = "<<tiennhuanbut<<endl;
}
main(){
sachgiaokhoa sgk;
sachbaitap sbt;
sachthamkhao stk;
sgk.khoitao();
sgk.tinhnhuanbutsachgiaokhoa();
sgk.inthongtin();

sbt.khoitao();
sbt.setsotap();
sbt.tinhnhuanbutsachbaitap();
sbt.inthongtin();

stk.khoitao();
stk.setsotrang();
stk.tinhnhuanbutsachthamkhao();
stk.inthongtin();
return 0;

}

