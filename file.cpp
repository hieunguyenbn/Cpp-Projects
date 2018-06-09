
/*Nhap mang n (n<100) quyen sach(ten, so trang, gia tien, ngay xuat ban). in ra mang do ra man hinh va ghi vao file data.txt */
#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
using namespace std;

struct sach {
	char ten[20];
	int sotrang;
	int giatien;
	char ngayxuatban[20];
};

//struct sach soluong[100];
int main() {
	sach SoLuong[100];
	int i, n;
	cout<<"Nhap so luong sach\n";
	cin>>n;
	for (i = 0; i < n; i++) {
	cout<<"Ten sach la: ";  fflush(stdin);
	cin.getline(SoLuong[i].ten,30);
	cout<<"So trang sach: "; cin>>SoLuong[i].sotrang;
	cout<<"Gia tien: "; cin>>SoLuong[i].giatien;
	cout<<"Ngay xuat ban: ";  fflush(stdin);
	cin.getline(SoLuong[i].ngayxuatban,20); fflush(stdin);
	}
	cout<<"Danh sach cac quyen sach la:\n";
//	for (i = 0; i < n; i++) {
//	cout<<SoLuong[i].ten<<endl;
//	cout<<SoLuong[i].sotrang<<endl;
//	cout<<SoLuong[i].giatien<<endl;
//	cout<<SoLuong[i].ngayxuatban<<endl;
//	}

	//FILE *fp = fopen("data3.txt","w");
	
	ifstream fileInput;
	fileInput.open("data3.txt",ios::out);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << std::endl;
		return -1;
	}
	while (!fileInput.eof()) {
	for (i = 0; i < n; i++) {
			fileInput >>
			std::cout << SoLuong[i].ten << std::endl;
			std::cout << SoLuong[i].sotrang << std::endl;
			std::cout << SoLuong[i].giatien << std::endl;
			std::cout << SoLuong[i].ngayxuatban << std::endl;
//			fprintf(fp,"%s\n",SoLuong[i].ten);
//			fprintf(fp,"%d\n",SoLuong[i].sotrang);
//			fprintf(fp,"%d\n",SoLuong[i].giatien);
//			fprintf(fp,"%s\n",SoLuong[i].ngayxuatban);
	}
	}
	return 0;
}

