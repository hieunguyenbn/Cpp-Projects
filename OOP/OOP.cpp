#include<iostream>
#include<string.h>
using namespace std;
int pc=100;
int cc=100;
class Nguoi{
	protected:
		char hoten[50]; 
		string diachi,sdt;
	public:
		Nguoi(){
			diachi="",sdt="";
		}
};
class Nhanvien: public Nguoi{
	int manv;
	string ngaykyhd;
	public:
		Nhanvien(){
			cout<< "nhap ten nhan vien: ";cin.getline(hoten,50);
			cout<< "nhap dia chi nhan vien: ";getline(cin,diachi);
			cout<< "sdt: ";getline(cin,sdt);
			cout<< "ngay ky hop dong: ";getline(cin,ngaykyhd);
			manv=cc;
			cc++;
		}
		INTT(){
			cout<< "\n\n_____________________";
			cout<< "\nma nhan vien: "<<manv;
			cout<< "\nten nhan vien: "<<hoten;
			cout<< "\ndia chi: "<<diachi;
			cout<< "\nsdt: "<<sdt;
			cout<< "\nngay ky hop dong: "<<ngaykyhd;
		}
		int getmanv(){
			return this->manv;
		}
		char* getten(){
			return this->hoten;
		}
		friend class BQL;
};
class Mathang{
	string tenhang,nhom;
	int ma,giaban, soluong;
	public:
		Mathang(){
			cout<< "nhap ten hang: ";getline(cin,tenhang);
			cout<< "nhom hang: ";getline(cin,nhom);
			cout<< "gia ban: ";cin>>giaban;
			cout<< "so luong: ";cin>>soluong;
			cin.ignore();
			ma=pc;
			pc++;
		}
		INTT(){
			cout<< "\n\n************";
			cout<< "\nma hang: "<<ma;
			cout<< "\nten hang: "<<tenhang;
			cout<< "\nnhom hang: "<<nhom;
			cout<< "\ngia ban: "<<giaban;
			cout<< "\nso luong: "<<soluong;
		}
		int getgia(){
			return this->giaban;
		}
		int getmamh(){
			return this->ma;
		}
		string getnhom(){
			return this->nhom;
		}
		friend class BQL;
};
class BQL{	
	public:
		Nhanvien *nv;
		Mathang **mh;
		void setnv(Nhanvien *nv){
			this->nv= nv;
		}
		Nhanvien getnv(){
			return *this->nv;
		}
		void setsl(int n){
			mh= new Mathang *[n];
		}
		void setmh(int i, Mathang *m){
			this-> mh[i]= m;
		}
		Mathang getmh(int i){
			return *this->mh[i];
		}
};
Nhanvien *nv;
Mathang *mh;
BQL *bql;
int m,n,sl,slmh[50],index[50];
void menu(){
	cout<< "\n1.nhap va xuat ten nhan vien"
	<< "\n2.nhap va xuat cac mat hang"
	<< "\n3.nhap va xuat bang ds ban hang"
	<< "\n4.xuat thong tin bang ds ban hang"
	<< "\n5.sap xep bang ds ban hang"
	<< "\n6.lap bang doanh thu";
	cout<< "\nmoi ban lua chon(enter 0 to exit): ";
}
void nv1(){
	cout<< "\nnhap so luong nhan vien: ";cin>>m;cin.ignore();
	nv= new Nhanvien[m];
	cout<< "\nThogn tin nv: ";
	for(int i=0;i<m;i++)
		nv[i].INTT();
}
void nv2(){
	cout<< "\nnhap so luong mat hang: ";cin>>n;cin.ignore();
	mh=new Mathang[n];
	cout<< "\nThong tin mat hang: ";
	for(int i=0;i<n;i++)
		mh[i].INTT();

}
void nv3(){
	int manv,mamh;
	cout<< "\nnhap so luong bang ds ban hang: ";cin>>sl;
	bql=new BQL[sl];
	for(int i=0;i<sl;i++){
		cout<< "\nnhap ma nhan vien: ";	cin>>manv;
		for(int j=0;j<m;j++){
			if(manv==nv[j].getmanv())
				bql[i].setnv(nv+j);
		}
		do{
			cout<< "\nnhap so luong mat hang ban duoc: ";cin>>slmh[i];
		}while(slmh[i]>5);
		bql[i].setsl(slmh[i]);
		cout<< "\nma cac mat hang ban duoc: ";
		for(int k=0;k<slmh[i];k++){
			cin>>mamh;
			for(int h=0;h<n;h++){
				if(mamh==mh[h].getmamh()){
					bql[i].setmh(k,mh+h);
				}
			}
		}
	}
}
void nv4(){
	cout<< "\nBang ds ban hang: ";
	for(int i=0;i<sl;i++){
		bql[i].getnv().INTT();
		cout<< "\nCac mat hang nhan vien nay ban duoc: ";
		for(int j=0;j<slmh[i];j++)
			bql[i].getmh(j).INTT();
	}
}
string tachten(char str[]){
	char *p= strtok(str, " ");
	int i=0;
	char a_str[5][10];
	while(p!='\0'){
		strcpy(a_str[i],p);
		i++;
		p=strtok('\0', " ");
	}
	return a_str[i-1];
}
string s1,s2;
void ad_swap(BQL &bql1, BQL &bql2){
	BQL temp= bql1;
	bql1=bql2;
	bql2=temp;
}
void nv5(){
	int lc;
	cout<< "\nsap xep theo(1.ten nhan vien \t2.nhom mat hang): ";cin>>lc;
	switch(lc){
		case 1:
			for(int i=0;i<sl;i++){
				for(int j=i+1;j<sl;j++){
					s1=tachten(bql[i].getnv().getten());
					s2=tachten(bql[j].getnv().getten());
					if(s1>s2){
						ad_swap(bql[i],bql[j]);
					}
				}
			}nv4();
		break;
		case 2:
			for(int i=0;i<sl;i++){
				for(int j1=0;j1<slmh[i];j1++){
					for(int j2=j1+1;j2<slmh[i];j2++)
						if(bql[i].getmh(j1).getnhom()>bql[i].getmh(j2).getnhom()){
							swap(bql[i].mh[j1],bql[i].mh[j2]);
						}
				}		
			}nv4();
		break;
	cout<< "\n";
	}
} 
int S[20]={0};
void nv6(){
	//lap bang thong ke doanh thu
	cout<< "\n";
	for(int i=0;i<sl;i++){
		bql[i].getnv().INTT();
		for(int j=0;j<slmh[i];j++)
			S[i]+=bql[i].getmh(j).getgia();
		cout<< "\nDoanh thu: "<<S[i];	
	}

}
int main(){
	int lc;
	do{
		menu();
		cin>>lc;
		switch(lc){
			case 1:nv1();break;// nv1 o day la viet tat cua nhiem vu 1, dung nham voi tu nhan vien nhe
			case 2:nv2();break;
			case 3:nv3();break;
			case 4:nv4();break;
			case 5:nv5();break;
			case 6:nv6();break;
			default:
			break;
		}
	}while(lc!=0);

}
//Khai b�o l?p Ngu?i (H? t�n, �?a ch?, S? �T)
//Khai b�o l?p Nh�n vi�n b�n h�ng k? th?a t? l?p Ngu?i v� c� th�m (m� NV, ng�y k� h?p d?ng), m� NV l� m?t s? nguy�n c� 4 ch? s?, t? d?ng tang. 
//Khai b�o l?p M?t h�ng trong kho g?m c�c thu?c t�nh (m� h�ng, T�n h�ng, Nh�m h�ng, Gi� b�n, S? lu?ng) � trong d� Nh�m h�ng c� th? l�: �i?n t?, �i?n l?nh, M�y t�nh, Thi?t b? van ph�ng. M� h�ng l� m?t s? nguy�n c� 4 ch? s?, t? d?ng tang. 
//Khai b�o l?p B?ng Danh s�ch b�n h�ng (trong m?t ng�y) l� b?n c?a l?p Nh�n vi�n v� l?p M?t h�ng trong d� v?i m?i nh�n vi�n, nh?p danh s�ch c�c m?t h�ng m� nh�n vi�n d� d� b�n du?c. Gi? s? m?i nh�n vi�n ch? tham gia b�n t?i da 5 m?t h�ng kh�c nhau.
//Vi?t chuong tr�nh trong ng�n ng? C++ th?c hi?n c�c y�u c?u sau: 
//1. Nh?p th�m m?t h�ng m?i v�o file MH.DAT. In ra danh s�ch c�c m?t h�ng d� c� trong file.
//2. Nh?p th�m nh�n vi�n v�o file NV.DAT. In ra danh s�ch nh�n vi�n d� c� trong file. 
//3. L?p B?ng danh s�ch b�n h�ng cho t?ng nh�n vi�n, luu v�o file QLBH.DAT v� in danh s�ch ra m�n h�nh (ch� �: c�ng m?t nh�n vi�n v?i m?t m?t h�ng th� kh�ng th? xu?t hi?n 2 l?n trong b?ng n�y). 
//4. S?p x?p danh s�ch B?ng danh s�ch b�n h�ng d� luu trong QLBH.DAT 
//a. Theo t�n nh�n vi�n 
//b. Theo nh�m m?t h�ng
//5. L?p b?ng k� doanh thu cho m?i nh�n vi�n
